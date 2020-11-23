#include <iostream>
#include <string>
using namespace std;


int main()
{
	string str;
	getline(cin, str);
	int size = str.size();
	string temp[100];
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (str[i] != ' ') {
			temp[j].push_back(str[i]);
		}
		else {
			j++;
		}
	}
	for (j; j >= 0; j--) {
		cout << temp[j]<< ' ';
	}
	cout << endl;
	return 0;
}