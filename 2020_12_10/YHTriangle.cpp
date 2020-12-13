#include <iostream>
using namespace std;

//当n<3时，没有偶数，输出-1；
//当n为奇数时，第一个偶数位置在第二，输出2；
//当n为偶数且能被4整除时，第一个偶数位置在第三，输出3；
//当n为偶数但不能被4整除时，偶数位置在第四，输出4
#if 0
int main()
{
    int n;
    while (cin >> n)
    {
        if (n <= 2)
            cout << -1 << endl;
        else
        {
            if (n % 2 == 1)
                cout << 2 << endl;
            else if (n % 4 == 2)
                cout << 4 << endl;
            else if (n % 4 == 0)
                cout << 3 << endl;
        }
    }
    return 0;
}
#endif