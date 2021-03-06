#include <iostream>
#include <algorithm>
using namespace std;

/*
从最小因子2到数字的最大因子数（数字的平方根）开始判断是否能够取余
可以则循环取余直到取余不为0，因子个数+1；否则使用下一个因子计算；
最终整除了各个因子数之后剩余的数字不为1则本身也是一个因子，因此因子数+1
*/

int main() {
    int n, k, i;
    while (cin >> n) {
        k = 0;
        for (i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                while (n % i == 0) {
                    n = n / i;
                }
                ++k;
            }
        }
        if (n != 1) {
            ++k;
        }
        cout << k << endl;
    }
    return 0;
}