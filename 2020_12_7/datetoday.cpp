#include <iostream>
using namespace std;

int M[2][13] = {
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};
int Y[2] = { 365, 366 };

int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    }
    else {
        return 0;
    }
}

int sumDay(int year, int month, int day) {
    int sumday = 0;
    int temp = isLeapYear(year);
    for (int i = 0; i < month; i++) {
        sumday += M[temp][i];
    }
    sumday += day;
    return sumday;
}

#if 0
int main()
{
    int y1, m1, d1;
    while (scanf("%04d %02d %02d", &y1, &m1, &d1) != EOF) {
        cout << sumDay(y1, m1, d1) << endl;
    }
    return 0;
}
#endif