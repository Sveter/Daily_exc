#include <iostream>
using namespace std;

#define PI 3.14

//�ܳ�����������̣����Ǿͽ���ȥ�ˡ�


int main()
{
	double n, r;
	while (cin >> n >> r)
	{
		double C = 2 * PI * r;
		if (C < n) {
			cout << "No" << endl;
		}
		else
		{
			cout << "Yes" << endl;
		}
	}
	return 0;
}