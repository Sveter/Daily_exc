/*
方法一：将输入数字转换成二进制，统计连续1的个数中最大的那个（这个大概是最先想到的吧）
方法二：对输入数字做位移运算，然后与原数相与(byte&=byte<<1)
*/

#include<iostream>
using namespace std;
int main() {
    int n, max = 0, count = 0;
    while (cin >> n) {
        max = 0, count = 0;
        while (n) {
            if (n % 2 != 0)
                count++;
            else
                count = 0;
            if (count > max)
                max = count;
            n /= 2;
        }
        cout << max << endl;
    }
    return 0;
}