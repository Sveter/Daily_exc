#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;//定义str为某个要输入的字符串
	cin >> str;

	string tmp;//定义一个临时字符串数组用来存放数字串
	string maxstr;//只存放最长的数字串
	int maxlength = 0;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			//次数的while循环和if中的判断语句一样，但是千万不可以少
			//while是为了将所有的数字串都加进tmp当中
			while (str[i] >= '0' && str[i] <= '9')
			{
				tmp += str[i++];
			}
			if (tmp.size() > maxlength)
			{
				maxstr = tmp;
				maxlength = tmp.size();
			}
		}
		tmp.clear();
	}
	cout << maxstr;
	return 0;
}