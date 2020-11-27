#include <iostream>
#include <string>
using namespace std;

bool is_pla(string str)
{
	int begin = 0;
	int end = str.size() - 1;
	while (begin < end)
	{
		if (str[begin] == str[end]) {
			begin++;
			end--;
		}
		else {
			return false;
		}
	}
	return true;
}

#if 0 
int main()
{
	string str, s, temp;
	getline(cin, str);
	getline(cin, s);
	int res = 0;
	for (int i = 0; i <= str.size(); i++)
	{
		temp = str;
		temp.insert(i, s);
		if (is_pla(temp)) {
			res++;
		}
	}
	cout << res << endl;
	return 0;
}
#endif
