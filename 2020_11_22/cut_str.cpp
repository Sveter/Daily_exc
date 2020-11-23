#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1;
	getline(cin, str1);
	string str2;
	getline(cin, str2);
	string res;
	for (int i = 0; i < str1.size(); i++)
	{
		int flag = str2.find(str1[i], 0);
		if (flag != -1) {
			continue;
		}
		else {
			res.push_back(str1[i]);
		}
	}
	cout << res << endl;
	system("pause");
	return 0;
}