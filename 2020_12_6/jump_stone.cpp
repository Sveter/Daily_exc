#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 思路
//将M个石板看做一个保存结果的数组jumpNum，每个jumpNum[i]中都储存着从N到当前位置最小的步数，如果是0，则说明不能走到这个位置。从起点开始对jumpNum进行遍历，先求当前位置的所有约数也就是当前位置可以向前走的步数，然后更新到能到达的位置的最小步数。之前没有来过这个位置，就将该位置更新为当前步数+1，否则更新为之前的步数和当前步数+1两者最小的，经过遍历一一次后得到结果，jumpNum[M]就是从N开始加，加到M的最少次数，如果是0，说明不可能加到M。


//计算约数，求除了1和本身的约数
void divisorNum(int n, vector<int>& divNum)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			divNum.push_back(i);
			//非平方数时还有另一个数也要加入
			if (n / i != i)
				divNum.push_back(n / i);
		}
	}
}
int Jump(int N, int M)
{
	//储存到达此stepNum点的步数，
	vector<int>stepNum(M + 1, 0);
	//初始N为1步，从N到N为1步
	stepNum[N] = 1;

	for (int i = N; i < M; i++)
	{
		//用来保存N的所有约数，即为从本身这个点开始能走的数量
		vector<int>divNum;

		//如果当前的位置是0代表这个点不能到，因为0没有约数
		if (stepNum[i] == 0)
			continue;

		//将当前位置可以走的步数存放在divisorNUm中
		divisorNum(i, divNum);
		//开始挨个试这些步数
		for (int j = 0; j < divNum.size(); j++)
		{
			//之前走到该点的步数为stepNum[divNum[j] + i]
			//走到当前位置的步数为stepNum[i] + 1
			//如果当前位置不是M，并且走的步数不为零，
			//那么当前能走到该点的步数要和之前该点的步数进行对比，取最小的
			if ((divNum[j] + i) <= M && stepNum[divNum[j] + i] != 0)
				stepNum[divNum[j] + i] = min(stepNum[divNum[j] + i], stepNum[i] + 1);
			//否则，如果当前位置不是M，
			//那么就说明走到这个位置的步数为0，就要将这个位置的步数更新
			else if ((divNum[j] + i) <= M)
				stepNum[divNum[j] + i] = stepNum[i] + 1;
		}
	}
	for (int i = 0; i < stepNum.size(); ++i)
	{
		cout << stepNum[i] << "->";
	}
	cout << endl;
	if (stepNum[M] == 0)
		return-1;
	else
		//初始化时多给了一步，故需要减1
		return stepNum[M] - 1;
}
int main()
{
	int n, m;
	cin >> n >> m;
	cout << Jump(n, m) << endl;
	return 0;
}