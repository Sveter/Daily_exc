#include <iostream>
#include <vector>
using namespace std;

// 把跳台阶问题的i-1和i-2，换成从0到i-1即可

class Solution {
public:
    int jumpFloorII(int number) {
        vector<int> dp(number + 1, 0);
        dp[0] = 1, dp[1] = 1;
        for (int i = 2; i <= number; i++)
            for (int j = 0; j <= i - 1; j++)
                dp[i] += dp[j];
        return dp[number];
    }
};