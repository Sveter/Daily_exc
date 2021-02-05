#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
思路： 用一个vector存储输入的收件人列表 注意需要去掉名字中的"" 把名字尾插到vector中,再用string name调用find在vector中找是否有一致的名字。
*/

int main()
{
	string namelist;
	string name;
	while (getline(cin, namelist))
	{
		getline(cin, name);
		vector<string> str;
		for (size_t i = 0; i < namelist.size(); ++i)
		{
			if (namelist[i] == '\"')//名字中有""的情况
			{
				str.push_back(namelist.substr(i + 1, namelist.find('\"', i + 1) - i - 1));//给vector中尾插去除""的名字
				i = namelist.find('\"', i + 1) + 1;
			}
			else//名字中无""的情况
			{
				if (namelist.find(',', i) == namelist.npos)//最后一个末尾名字 其后没有,字符
				{
					str.push_back(namelist.substr(i, namelist.size() - i));
					i = namelist.size();
				}
				else//中间都有,隔开的名字
				{
					str.push_back(namelist.substr(i, namelist.find(',', i) - i));//需要把,一起尾插进去隔开 防止前后名字重复
					i = namelist.find(',', i);
				}
			}
		}
		if (find(str.begin(), str.end(), name) != str.end())
			cout << "Ignore" << endl;
		else
			cout << "Important!" << endl;
	}
	return 0;
}
