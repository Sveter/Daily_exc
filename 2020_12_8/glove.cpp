#include <iostream>
#include <vector>
using namespace std;

//思路：假设有一序列 a1<a2<a3<a4<...<an，选出多少个能够保证覆盖n种颜色？
//答案是 sum(a1...an)-a1+1，类似鸽巢原理
//所以先求出左手套和右手套哪边能够覆盖n种颜色，而且还能少拿手套？
//答案是 min(leftSum-leftMin+1,rightSum-rightMin+1)，这个确定以后，
//只需要在另一边随便选择一个就能够保证至少有一种颜色匹配了
//另外要注意某种颜色手套数为0的情况

class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
        // write code here
        int left_sum = 0, left_min = INT_MAX;
        int right_sum = 0, right_min = INT_MAX;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            // 左边或者右边没有的时候需要全部拿走(最差结果)
            if (left[i] * right[i] == 0)
            {
                sum += left[i] + right[i];
            }
            // 找到左边和右边分别最少的颜色的数量并计算总和
            else {
                left_sum += left[i];
                right_sum += right[i];
                left_min = min(left[i], left_min);
                right_min = min(right[i], right_min);
            }
        }
        // 找到左边和右边中较小的值，在另一边直接拿一个就可以保证题意
        return sum + min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;
    }
};