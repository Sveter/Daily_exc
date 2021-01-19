#include <iostream>
#include <string>
using namespace std;

string get_reverse(string str)
{
	int begin = 0;
	int end = str.size() - 1;
	string res;
	while (end != begin)
	{
		res.push_back(str[end]);
		end--;
	}
	res.push_back(str[begin]);
	return res;
}

#if 0
int main()
{
	string str;
	while (cin >> str)
	{
		cout << get_reverse(str) << endl;
	}
	return 0;
}
#endif 