/*
* 走方格的方案数
* 思路:
    用递归来做，将右下角看做原点(0, 0)，左上角看做坐标(m, n)，下图所示：
    从(m, n)—>(0, 0)就分两步走：
    往右走一步：f(m, n - 1)—>(0, 0) 加上下走一步：f(m - 1, n)—>(0, 0)
    注意：但凡是触碰到边界，也就是说f(x, 0)或者f(0,x)都只有一条直路可走了，这里的x是变量。
    f(m, n) = f(m, n - 1) + f(m - 1, n)
*/

//#include <iostream>
//
//using namespace std;
//
//int func(int m, int n) {
//    if (m == 0 || n == 0) {
//        return 1;
//    }
//    return func(m, n - 1) + func(m - 1, n);
//}
//int main() {
//    int m, n;
//    while (cin >> m >> n) {
//        cout << func(m, n) << endl;
//    }
//
//    return 0;
//}

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int m, n;
	while (cin >> m >> n) {
		vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				if (i == 0 && j == 0) {
					dp[i][j] = 1;
					continue;
				}
				if (i == 0) {    // 上边界
					dp[i][j] = dp[i][j - 1];
				}
				else if (j == 0) {    // 左边界
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
			}
		}
		cout << dp[n][m] << endl;
	}

	return 0;
}