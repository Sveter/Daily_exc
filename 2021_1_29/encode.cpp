#include <iostream>
#include <string>

using namespace std;

//��ԭ�ַ���������ת����һ����F�CZ��ֻ��Ҫ��ASCII���Ӧ�� 5����һ���� A�CE����ASCII ���Ӧ��21 �������ո�ֱ�������������������Ľ����

string Change(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		//�ֱ�ת����ĸ
		if (s[i] >= 'F' && s[i] <= 'Z')
			s[i] -= 5;
		else if (s[i] >= 'A' && s[i] <= 'E')
			s[i] += 21;
		// �����ո�ֱ����������
		else
			continue;
	}
	return s;
}
#if 0
int main()
{
	string s;
	//�пո���ַ���Ҫ��getline ����
	while (getline(cin, s))
	{
		string s1 = Change(s);
		cout << s1 << endl;
	}
	return 0;
}
#endif
