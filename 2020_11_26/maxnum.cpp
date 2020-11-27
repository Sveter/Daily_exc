#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}


	int max = v[0];
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		sum += v[i];
		//每加一个数据，和之前的sum_max比一下，大的话就说说明要加上这个数
		if (sum > max)
		{
			max = sum;
		}
		//sum<0了，说明肯定有负数出现了，负数肯定是拉后腿的那个数，因此要将sum清空，开始下一次新的累计
		if (sum < 0)
		{
			sum = 0;
		}
	}

	cout << max << endl;
	return 0;
}