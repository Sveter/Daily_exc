#include<iostream>
#include<string>
#include <algorithm>
using namespace std;

// ������Ŀ������֪�����������ȫ��Ϊstring����
// �����Ӧλ�ĺ�(��Ҫ�������Ե�λ�Ľ�λcarry / 10)�����ܵĽ���� carry = 0 ~19 ��19�������9 + 9�����һ�Ҫ�������Ե�λ��λ1��
// ��˵�ǰλ�Ľ������carry % 10(��ӵ����ص�string����)����λ��carry / 10(����9���λΪ1������Ϊ0)
// ���ռ��������Ҫ�ж�carry���ս��Ϊ1����Ϊ0��Ϊ1˵����Ҫ���һλ���õ����ս����Ҫ���������

string StrAdd(string str1, string str2)
{
	size_t str1Length = str1.size();
	size_t str2Length = str2.size();
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	string rStr;
	int flag = 0;
	for (int i = 0; i < str1Length; i++)
	{
		char temp = str1[i] - '0' + str2[i] - '0' + flag;
		temp = temp < 10 ? (flag = 0, temp) : (flag = 1, temp - 10);
		rStr += (temp + '0');
	}
	for (int j = str1Length; j < str2Length; j++)
	{
		char temp = str2[j] - '0' + flag;
		temp = temp < 10 ? (flag = 0, temp) : (flag = 1, temp - 10);
		rStr += (temp + '0');
	}
	if (flag == 1)
		rStr += '1';
	return rStr;
}
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		size_t nLength1 = str1.size();
		size_t nLength2 = str2.size();
		string output_str;
		if (nLength1 < nLength2)
			output_str = StrAdd(str1, str2);
		else
			output_str = StrAdd(str2, str1);
		reverse(output_str.begin(), output_str.end());
		cout << output_str << endl;
	}
	return 0;
}