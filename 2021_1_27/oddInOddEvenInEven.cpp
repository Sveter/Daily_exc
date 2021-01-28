#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     *  奇数位上都是奇数或者偶数位上都是偶数
     *  输入：数组arr，长度大于2
     *  len：arr的长度
     *  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
     * 思路：
	 *  定义两个下标分别用来遍历奇数位和偶数位
	 *  在不一致的位置(奇数位上非奇数或偶数位上非偶数)停下来
	 *  当两个下标都停下来时就对两个数进行位置交换，再继续向后寻找直到有一个下标到末尾
     */
    void oddInOddEvenInEven(vector<int>& arr, int len) {
        int i = 0, j = 1;
        while (i < len && j < len)
        {
            if (arr[len - 1] % 2 == 0)
            {
                swap(arr[len - 1], arr[i]);
                i += 2;
            }
            else
            {
                swap(arr[len - 1], arr[j]);
                j += 2;
            }
        }
    }
};