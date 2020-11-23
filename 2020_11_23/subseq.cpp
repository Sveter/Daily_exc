#include <iostream>
#include <vector>
using namespace std;

/*解题思路：
1）本题依次比较整个数组
2）a[i+1]>a[i] ，则进入大于操作，直到遍历到下一个值不大于等于为止count++，然后进行下一位置的判断
3）a[i+1]<a[i],则进入小于操作，直到遍历到下一个值不小于等于为止count++，然后进行下一位置的判断
4）a[i+1] == a[i]不进行操作，进行下一位置遍历
 
本题注意点：
1）本题开始比较a[i+1]与a[i]进行比较，为了避免越界，数组定义为n+1个，同时给a[n] = 0;
分为三种情况，若到a[n-1] 的最后一组是非递减序列，a[n]=0  在增遍历中执行完i=n-1 for循环使得i=n，
不执行for循环结束，因此不影响
第二种情况  若到a[n-1] 的最后一组是非递增序列，a[n]=0  在减遍历中执行完i=n-1 for循环使得i=n，
不执行for循环结束，因此不影响
第三种情况  1 2 1 2 1最后一个数是单独的情况，执行完最后一组1 2 i=3 ，for循环i++，此时i=4，
<=4 继续执行，此时a[5]为0，a[4]<a[5]进入降处理，count++;i超出范围退出循环。
所以a[n]为0保证了结果的正确性。因此成立
 
2）本题中全部相等情况，只执行了i++，未对count进行其他相应处理，所以全部相等情况应进行特殊处理。
首先定义equal，每次相等equal++，n个数，共有n-1组相等，因此当equal==n-1表示全部相等的情况，此时应输出1
*/

int get_subseq_num(vector<int> vec)
{
    int count = 0;
    int i = 0;
    int n = vec.size();
    while (i < n) {
        if (vec[i] < vec[i + 1]) {
            //判断递增情况
            while (i < n - 1 && vec[i] <= vec[i + 1]) {
                i++;
            }
            count++;
            i++;
        }
        else if (vec[i] == vec[i + 1]) {
            //相同
            i++;
        }
        else if (vec[i] > vec[i + 1]) {
            //递减情况
            while (i < n - 1 && vec[i] >= vec[i + 1]) {
                i++;
            }
            count++;
            i++;
        }
    }
	return count;
}

#if 0
int main()
{
	int n;
	cin >> n;
	vector<int> seq;
	int i = 0;
	int c = 0;
	while (i < n)
	{
		cin >> c;
		seq.push_back(c);
		i++;
	}
	cout << get_subseq_num(seq) << endl;
	return 0;
}
#endif