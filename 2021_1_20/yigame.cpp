#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    else;
    return gcd(b, a % b);
}

#if 0
int main()
{
    int n, a;
    while (cin >> n >> a)
    {
        vector<int> b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        int c = a;
        for (int j = 0; j < n; j++)
        {
            if (c >= b[j])
            {
                c += b[j];
            }
            else
            {
                int temp = gcd(c, b[j]);
                c += temp;
            }
        }
        cout << c << endl;
    }

	return 0;
}
#endif