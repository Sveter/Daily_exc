#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ˼·��ͨ���Կո��˫����Ϊ�����ͳ�Ʋ�������������˫���ţ�ͨ�����flag����֤˫�����еĿո������

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
            flag = ~flag;  // flag Ϊ0 ���Ϊ1��ʾ���ڵ�һ�γ����ˡ� ��Ϊ1�����Ϊ0��ʾ��������
        }
        else if (' ' == str[i] && 0 == flag)
        {
            svec.push_back(temp);
            temp = "";
        }
        else
            temp += str[i];
    }
    svec.push_back(temp);  // ���������һ��temp
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

// ͨ����80%
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