#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 思路：通过以空格和双引号为间隔，统计参数个数。对于双引号，通过添加flag，保证双引号中的空格被输出。

void cmdExplain(const string& str)
{
    string temp = "";
    vector<string> svec;
    int size = str.size();
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        if ('"' == str[i])
        {
            flag = ~flag;  // flag 为0 则变为1表示现在第一次出现了“ ，为1，则变为0表示“抵消了
        }
        else if (' ' == str[i] && 0 == flag)
        {
            svec.push_back(temp);
            temp = "";
        }
        else
            temp += str[i];
    }
    svec.push_back(temp);  // 别忘记最后一个temp
    int t = svec.size();
    cout << t << endl;
    for (int i = 0; i < t; i++)
        cout << svec[i] << endl;
}

#if 0
int main()
{
    string str;
    while (getline(cin, str))
    {
        cmdExplain(str);
    }
}
#endif

// 通过率80%
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	string str;
//	while (getline(cin, str))
//	{
//		vector<string> vs;
//		string s;
//		int flag = 0;
//		for (int i = 0; i < str.size(); i++)
//		{
//			if (str[i] == ' ')
//			{
//				vs.push_back(s);
//				s.clear();
//			}
//			else if (str[i] == '\"' || flag == 1)
//			{
//				flag = 1;
//				if (str[i+1] == '\"')
//				{
//					i++;
//					flag = 0;
//				}
//
//				if (flag == 1)
//					s += str[i + 1];
//			}
//			else
//				s += str[i];
//			if (i+1 == str.size())
//			{
//				vs.push_back(s);
//				s.clear();
//			}
//		}
//		cout << vs.size() << endl;
//		for (int i = 0; i < vs.size(); i++)
//		{
//			cout << vs[i] << endl;
//		}
//	}
//	return 0;
//}