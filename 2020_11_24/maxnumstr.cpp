#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;//����strΪĳ��Ҫ������ַ���
	cin >> str;

	string tmp;//����һ����ʱ�ַ�����������������ִ�
	string maxstr;//ֻ���������ִ�
	int maxlength = 0;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			//������whileѭ����if�е��ж����һ��������ǧ�򲻿�����
			//while��Ϊ�˽����е����ִ����ӽ�tmp����
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