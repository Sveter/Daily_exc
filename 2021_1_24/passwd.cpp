#include <iostream>
using namespace std;

//矩阵运算规则：
//
//| a11 a12 | *| b11 b12 |= | a11 * b11 + a12 * b12 a11 * b21 + a12 * b22|
//|a21 a22| |b21 b22| |a21 * b11 + a22 * b12 a21 * b21 + a22 * b22 |
//将b矩阵带入举证运算公式，可得:
//
//   f(n - 1)             f(n)
//| a11 a12 | *| 1 1 |= | a11 + a12 a11|
//|a21 a22| |1 0| |a21 + a22 a21 |
//也就是说，每次n加1，都是将f(n - 1)的结果进行上面的求和计算，
//算出的结果表现的特征就是斐波拉契尔数列。

#if 0
int main(int argc, const char* argv[]) {
    //建立一张表，用于记录斐波拉契尔数列的各项值
    int fTable[10001] = { 0, 1, 2 };
    for (int i = 3; i < 10001; ++i) {
        fTable[i] = fTable[i - 1] + fTable[i - 2];
        fTable[i] = fTable[i] % 10000;
    }
    int count = 0;
    //scanf返回值为正确输出数据的变量个数，当一个变量都没有成功获取数据时，此时返回-1
    while (scanf("%d", &count) != -1) {
        for (int i = 0; i < count; ++i) {
            int number = 0;
            scanf("%d", &number);
            //“%04d”的作用是输出长度不少于4位，少于用0b填充
            printf("%04d", fTable[number]);
        }
        printf("\n");
    }
    return 0;
}
#endif