#include <iostream>
#include <algorithm>
using namespace std;

/*
����С����2�����ֵ���������������ֵ�ƽ��������ʼ�ж��Ƿ��ܹ�ȡ��
������ѭ��ȡ��ֱ��ȡ�಻Ϊ0�����Ӹ���+1������ʹ����һ�����Ӽ��㣻
���������˸���������֮��ʣ������ֲ�Ϊ1����Ҳ��һ�����ӣ����������+1
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