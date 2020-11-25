#include <iostream>

using namespace std;

int main()
{
    int a[4];
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    int A, B, C;
    A = (a[0] + a[2]) / 2;
    B = (a[1] + a[3]) / 2;
    C = (a[3] - a[1]) / 2;
    if (A - B == a[0] && B - C == a[1] && A + B == a[2] && B + C == a[3])
    {
        cout << A << " " << B << " " << C << endl;
    }
    else
        cout << "No" << endl;
    return 0;
}