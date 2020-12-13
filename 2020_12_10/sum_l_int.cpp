#include<iostream>
#include<string>
#include <algorithm>
using namespace std;

// 根据题目描述可知输入输出参数全部为string类型
// 计算对应位的和(需要加上来自低位的进位carry / 10)，可能的结果是 carry = 0 ~19 （19的情况是9 + 9，并且还要加上来自低位进位1）
// 因此当前位的结果就是carry % 10(添加到返回的string类中)，进位是carry / 10(大于9则进位为1，否则为0)
// 最终计算完毕需要判断carry最终结果为1还是为0，为1说明还要添加一位，得到最终结果需要将结果逆置

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