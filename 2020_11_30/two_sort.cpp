#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
* �������򷽷�
* ˼·��
* 1. �жϳ���i = 1,  v[i-1].size, v[i].size()
* 2. �ж��ֵ��� i = 1�� v[i - 1] >= v[i]
* 3. ��������������ж����������
*/

bool Dic_Sort(vector<string> vs)
{
	for (int i = 1; i < vs.size(); i++)
	{
		if (vs[i - 1] >= vs[i])
		{
			return false;
		}
	}
	return true;
}

bool Length_Sort(vector<string> vs)
{
	for (int i = 1; i < vs.size(); i++)
	{
		if (vs[i - 1].size() >= vs[i].size())
		{
			return false;
		}
	}
	return true;
}
#if 0
int main()
{
	int n;
	cin >> n;
	vector<string> v;
	v.resize(n);
	for (auto& str : v)
		cin >> str;
	bool res1 = Length_Sort(v);
	bool res2 = Dic_Sort(v);
	if (res1 && res2) {
		cout << "both" << endl;
	}
	else if (res1 && !res2) {
		cout << "lengths" << endl;
	}
	else if (!res1 && res2) {
		cout << "lexicographically" << endl;
	}
	else {
		cout << "none" << endl;
	}
	return 0;
}
#endif
