#include <iostream>
using namespace std;

//�����������
//
//| a11 a12 | *| b11 b12 |= | a11 * b11 + a12 * b12 a11 * b21 + a12 * b22|
//|a21 a22| |b21 b22| |a21 * b11 + a22 * b12 a21 * b21 + a22 * b22 |
//��b��������֤���㹫ʽ���ɵ�:
//
//   f(n - 1)             f(n)
//| a11 a12 | *| 1 1 |= | a11 + a12 a11|
//|a21 a22| |1 0| |a21 + a22 a21 |
//Ҳ����˵��ÿ��n��1�����ǽ�f(n - 1)�Ľ�������������ͼ��㣬
//����Ľ�����ֵ���������쳲����������С�

#if 0
int main(int argc, const char* argv[]) {
    //����һ�ű����ڼ�¼쳲����������еĸ���ֵ
    int fTable[10001] = { 0, 1, 2 };
    for (int i = 3; i < 10001; ++i) {
        fTable[i] = fTable[i - 1] + fTable[i - 2];
        fTable[i] = fTable[i] % 10000;
    }
    int count = 0;
    //scanf����ֵΪ��ȷ������ݵı�����������һ��������û�гɹ���ȡ����ʱ����ʱ����-1
    while (scanf("%d", &count) != -1) {
        for (int i = 0; i < count; ++i) {
            int number = 0;
            scanf("%d", &number);
            //��%04d����������������Ȳ�����4λ��������0b���
            printf("%04d", fTable[number]);
        }
        printf("\n");
    }
    return 0;
}
#endif