#include <iostream>
#include <vector>
using namespace std;

/**
 * ÿ�ζ�ȡһ����֮�����������k��ϴ�ƺ��λ�ã�ֻ��һ������Ϊ2n�����������
 * ���ݵ�ǰ����λ�ã������������һ��ϴ�ƺ��λ��
 * �����ǰ��С�ڵ���n���������֣��������´γ��ֵ�λ���� 2*��ǰλ��-1
 * �����ǰλ�ô���n���������֣�,�����´γ��ֵ�λ���� 2*����ǰλ�� - n��
 */
#if 0
int main()
{
	int T;
	int n, k;
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
        int num = 2 * n;
        vector<int> table(num);
        for (int i = 0; i < num; ++i)
            cin >> table[i];
        while (k--)
        {
            vector<int> n1(table.begin(), table.end());
            for (int i = 0; i < n; ++i)
            {
                table[2 * i] = n1[i];
                table[2 * i + 1] = n1[i + n];
            }
        }
        for (int i = 0; i < num - 1; ++i)
            cout << table[i] << " ";
        cout << table[num - 1] << endl;

	}
	return 0;
}
#endif