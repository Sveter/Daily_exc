#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
˼·�� ��һ��vector�洢������ռ����б� ע����Ҫȥ�������е�"" ������β�嵽vector��,����string name����find��vector�����Ƿ���һ�µ����֡�
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
			if (namelist[i] == '\"')//��������""�����
			{
				str.push_back(namelist.substr(i + 1, namelist.find('\"', i + 1) - i - 1));//��vector��β��ȥ��""������
				i = namelist.find('\"', i + 1) + 1;
			}
			else//��������""�����
			{
				if (namelist.find(',', i) == namelist.npos)//���һ��ĩβ���� ���û��,�ַ�
				{
					str.push_back(namelist.substr(i, namelist.size() - i));
					i = namelist.size();
				}
				else//�м䶼��,����������
				{
					str.push_back(namelist.substr(i, namelist.find(',', i) - i));//��Ҫ��,һ��β���ȥ���� ��ֹǰ�������ظ�
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
