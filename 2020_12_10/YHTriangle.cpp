#include <iostream>
using namespace std;

//��n<3ʱ��û��ż�������-1��
//��nΪ����ʱ����һ��ż��λ���ڵڶ������2��
//��nΪż�����ܱ�4����ʱ����һ��ż��λ���ڵ��������3��
//��nΪż�������ܱ�4����ʱ��ż��λ���ڵ��ģ����4
#if 0
int main()
{
    int n;
    while (cin >> n)
    {
        if (n <= 2)
            cout << -1 << endl;
        else
        {
            if (n % 2 == 1)
                cout << 2 << endl;
            else if (n % 4 == 2)
                cout << 4 << endl;
            else if (n % 4 == 0)
                cout << 3 << endl;
        }
    }
    return 0;
}
#endif