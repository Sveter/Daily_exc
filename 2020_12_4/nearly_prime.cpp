#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// 分析：从i从1开始到n/2，判断i和n-i同时是素数，一直到最后，最后一对数就是满足题意的。
// 需要注意的是输出的时候要先输出小的，而且n/2要取到

//判断一个数是否为素数
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
        //注意边界是<=n/2
        for (int i = 1; i <= n / 2; i++)
        {
            if (is_prime(i) && (is_prime(n - i)))
            {
                v.push_back(i);
                v.push_back(n - i);
            }
        }
        //注意放的时候先放小的，取的时候也应该先取小的
        cout << v[v.size() - 2] << endl;
        cout << v[v.size() - 1] << endl;
    }
    return 0;
}