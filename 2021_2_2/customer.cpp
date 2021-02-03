#include<iostream>
using namespace std;

int main()
{
    long long int arr[80];
    arr[0] = 1;
    arr[1] = 1;
    int t = 2;
    int n = 0;
    int m = 0;
    while (cin >> m >> n)
    {
        if (n >= t)
        {
            t = n;
            for (int i = 2; i <= 80; ++i)
            {
                arr[i] = arr[i - 1] + arr[i - 2];
            }
        }
        long long int k = 0;
        for (int i = m - 1; i < n; ++i)
        {
            k = k + arr[i];
        }
        cout << k << endl;
    }


    return 0;
}