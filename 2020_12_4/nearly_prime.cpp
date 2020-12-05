#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// ��������i��1��ʼ��n/2���ж�i��n-iͬʱ��������һֱ��������һ����������������ġ�
// ��Ҫע����������ʱ��Ҫ�����С�ģ�����n/2Ҫȡ��

//�ж�һ�����Ƿ�Ϊ����
bool is_prime(int num)
{
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}


int main()
{
    int n = 0;
    while (cin >> n)
    {
        vector<int> v;
        //ע��߽���<=n/2
        for (int i = 1; i <= n / 2; i++)
        {
            if (is_prime(i) && (is_prime(n - i)))
            {
                v.push_back(i);
                v.push_back(n - i);
            }
        }
        //ע��ŵ�ʱ���ȷ�С�ģ�ȡ��ʱ��ҲӦ����ȡС��
        cout << v[v.size() - 2] << endl;
        cout << v[v.size() - 1] << endl;
    }
    return 0;
}