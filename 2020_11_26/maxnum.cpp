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
		//ÿ��һ�����ݣ���֮ǰ��sum_max��һ�£���Ļ���˵˵��Ҫ���������
		if (sum > max)
		{
			max = sum;
		}
		//sum<0�ˣ�˵���϶��и��������ˣ������϶��������ȵ��Ǹ��������Ҫ��sum��գ���ʼ��һ���µ��ۼ�
		if (sum < 0)
		{
			sum = 0;
		}
	}

	cout << max << endl;
	return 0;
}