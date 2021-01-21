#include <iostream>
#include <string>
using namespace std;

// 思路：从前往后找str[i]和从后往前找str[i]判断两个位置是否相等

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