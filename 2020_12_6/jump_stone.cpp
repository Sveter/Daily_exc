#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// ˼·
//��M��ʯ�忴��һ��������������jumpNum��ÿ��jumpNum[i]�ж������Ŵ�N����ǰλ����С�Ĳ����������0����˵�������ߵ����λ�á�����㿪ʼ��jumpNum���б���������ǰλ�õ�����Լ��Ҳ���ǵ�ǰλ�ÿ�����ǰ�ߵĲ�����Ȼ����µ��ܵ����λ�õ���С������֮ǰû���������λ�ã��ͽ���λ�ø���Ϊ��ǰ����+1���������Ϊ֮ǰ�Ĳ����͵�ǰ����+1������С�ģ���������һһ�κ�õ������jumpNum[M]���Ǵ�N��ʼ�ӣ��ӵ�M�����ٴ����������0��˵�������ܼӵ�M��


//����Լ���������1�ͱ����Լ��
void divisorNum(int n, vector<int>& divNum)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			divNum.push_back(i);
			//��ƽ����ʱ������һ����ҲҪ����
			if (n / i != i)
				divNum.push_back(n / i);
		}
	}
}
int Jump(int N, int M)
{
	//���浽���stepNum��Ĳ�����
	vector<int>stepNum(M + 1, 0);
	//��ʼNΪ1������N��NΪ1��
	stepNum[N] = 1;

	for (int i = N; i < M; i++)
	{
		//��������N������Լ������Ϊ�ӱ�������㿪ʼ���ߵ�����
		vector<int>divNum;

		//�����ǰ��λ����0��������㲻�ܵ�����Ϊ0û��Լ��
		if (stepNum[i] == 0)
			continue;

		//����ǰλ�ÿ����ߵĲ��������divisorNUm��
		divisorNum(i, divNum);
		//��ʼ��������Щ����
		for (int j = 0; j < divNum.size(); j++)
		{
			//֮ǰ�ߵ��õ�Ĳ���ΪstepNum[divNum[j] + i]
			//�ߵ���ǰλ�õĲ���ΪstepNum[i] + 1
			//�����ǰλ�ò���M�������ߵĲ�����Ϊ�㣬
			//��ô��ǰ���ߵ��õ�Ĳ���Ҫ��֮ǰ�õ�Ĳ������жԱȣ�ȡ��С��
			if ((divNum[j] + i) <= M && stepNum[divNum[j] + i] != 0)
				stepNum[divNum[j] + i] = min(stepNum[divNum[j] + i], stepNum[i] + 1);
			//���������ǰλ�ò���M��
			//��ô��˵���ߵ����λ�õĲ���Ϊ0����Ҫ�����λ�õĲ�������
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
		//��ʼ��ʱ�����һ��������Ҫ��1
		return stepNum[M] - 1;
}
int main()
{
	int n, m;
	cin >> n >> m;
	cout << Jump(n, m) << endl;
	return 0;
}