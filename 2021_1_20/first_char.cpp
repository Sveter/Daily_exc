#include <iostream>
#include <string>
using namespace std;

// ˼·����ǰ������str[i]�ʹӺ���ǰ��str[i]�ж�����λ���Ƿ����

int main()
{
	string str;
	while (getline(cin, str))
	{
        int i;
        for (i = 0; i < str.size(); i++)
        {
            if (str.find(str[i]) == str.rfind(str[i]))
            {
                cout << str[i] << endl;
                break;
            }
        }
        if (i == str.size())
            cout << -1 << endl;
        }
	return 0;
}