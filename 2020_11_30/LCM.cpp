#include <iostream>
using namespace std;

/*
* ����С������
* ˼·��
* ��С������ = �������/���Լ��
* ���Լ����շת�����
*/

int gcd(int a, int b)
{
	while (a % b)
	{
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return b;
}

int main()
{
	int A, B;
	cin >> A >> B;
	int v;
	if (A > B)
	{
		v = gcd(A, B);
	}
	else
	{
		v = gcd(B, A);
	}
	cout << A * B / v << endl;
	return 0;
}