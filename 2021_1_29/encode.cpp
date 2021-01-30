#include <iostream>
#include <string>

using namespace std;

//将原字符分两部分转化，一部分F–Z，只需要将ASCII码对应减 5；另一部分 A–E，将ASCII 码对应加21 ，遇到空格直接跳过，即可完成密码的解读。

string Change(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		//分别转化字母
		if (s[i] >= 'F' && s[i] <= 'Z')
			s[i] -= 5;
		else if (s[i] >= 'A' && s[i] <= 'E')
			s[i] += 21;
		// 遇到空格直接跳过处理
		else
			continue;
	}
	return s;
}
#if 0
int main()
{
	string s;
	//有空格的字符串要用getline 接收
	while (getline(cin, s))
	{
		string s1 = Change(s);
		cout << s1 << endl;
	}
	return 0;
}
#endif
