#include <iostream>
#include <vector>
using namespace std;

/*
动态规划：01背包问题(无物品价值)，思想相同，题目最终要求有些变化

min为最轻物品的重量，sum为所有物品总重量

假设有一个能装入容量为C(C在[min,sum]间取值)的背包和n件重量分别为w1,w2,…,wn的物品，能否从n件物品中挑选若干件恰好装满背包，要求输出不满足条件的最小容量。
以数组{3,2,5}为例，dp初始化全为0
接下来进行逆序分析：

(逆序是因为同一件物品只能放一次)
(因为分情况时容量要减去当前物品重量，所以高容量的值要用低容量来更新，可能造成重复放入)
(举个例子，判断3是否放入时，如果是顺序的话dp[3]=dp[3]+3放了一次3,之后dp[6]=dp[3]+3又放了一次，就重复了)

判断某一物品能否放入时直接忽略容量小于该物品质量的情况

先判断3是否放入
对于容量为3及以上的都选择放入，对应dp值更新为3

再判断2是否放入
对于容量为5及以上的都选择放入，加上3，对应dp值更新为5
对于容量为3、4的如果放入后剩余容量不够放其他物品，比较3后选择较大值，对应dp值仍为3
容量为2的选择放入，对应dp值更新为2

最后判断5是否放入
对于容量为10的选择放入，加上5，dp值更新为3
对于容量为9的选择放入，加上3， dp值更新为8
对于容量为8的选择放入，加上3， dp值更新为8
对于容量为7的选择放入，加上2， dp值更新为7
对于容量为6的选择放入，dp值更新为5
对于容量为5的选择放入，dp值更新为5

在前i个状态下的最值的前提下，考虑第i个值是否使用，从而把前i个状态的最值求出来,这就是动态规划的思想
*/

class Solution {
public:
	/**
	 *	正数数组中的最小不可组成和
	 *	输入：正数数组arr
	 *	返回：正数数组中的最小不可组成和
	 */
	int getFirstUnFormedNum(vector<int> arr, int len) {
        int sum = 0, min = arr[0];
        for (int i = 0; i < len; ++i)
        {
            sum += arr[i];
            if (arr[i] < min)
                min = arr[i];
        }
        vector<int> dp(sum + 1, 0);
        for (int i = 0; i < len; ++i)
        {
            for (int j = sum; j >= arr[i]; --j)
            {
                if (dp[j - arr[i]] + arr[i] > dp[j])
                {
                    dp[j] = dp[j - arr[i]] + arr[i];
                }
            }
        }

        for (int i = min; i <= sum; ++i)
        {
            if (i != dp[i])
                return i;
        }
        return sum + 1;
	}
};

#if 0
int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        Solution s;
        cout << s.getFirstUnFormedNum(a, n) << endl;
    }
    return 0;
}
#endif