#include <iostream>
using namespace std;

/*
* 求最小公倍数
* 思路：
* 最小公倍数 = 两数相乘/最大公约数
* 最大公约数：辗转相除法
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