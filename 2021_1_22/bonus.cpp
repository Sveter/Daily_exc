#include <iostream>
#include <vector>
using namespace std;

// 当前点的最大总价值 = max(上面点最大总价值，左边点的最大总价值) + 当前点价值
// (0, 0)点以及第一行和第一列要先初始化一波

class Bonus {
public:
    int dp[6][6];
    int getMost(vector<vector<int> > board) {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = board[0][0];
        for (int i = 1; i < 6; i++) dp[0][i] = dp[0][i - 1] + board[0][i];
        for (int i = 1; i < 6; i++) dp[i][0] = dp[i - 1][0] + board[i][0];
        for (int i = 1; i < 6; i++)
            for (int j = 1; j < 6; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + board[i][j];
            }
        return dp[5][5];
    }
};