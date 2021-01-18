#include <iostream>

using namespace std;

// 解法一：能喝的瓶数=目前空瓶数除以2
// 解法二：n/3是能直接换到的汽水数，n%3+n/3是新换到的汽水瓶子+上次换剩下的

int get_drink(int num)
{
	int temp1 = num / 3; //3
	int temp2 = num % 3; //1
	int temp3 = 0;
	int sum = temp1; // 3
	while (temp1 != 0)
	{
		temp3 = temp1 + temp2; //4
		temp1 = (temp3) / 3; //1
		temp2 = (temp3) % 3; //1
		sum += temp1;
		if ((temp1 + temp2) == 2) {
			temp1 = 0;
			sum = sum + 1;
		}
	}
	return sum;
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		if (n == 0)
			break;
		cout << get_drink(n);
	}
	return 0;
}