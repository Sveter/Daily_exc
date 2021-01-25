#include<iostream>
#include<string>
using namespace std;

// 由于可能输入的数字过大，先用string表示它的类型，之后我们先自行将其各个位上的数字相加依次，
//结果最大也就1000*9=9000,之后我们再用int型的数据表示。接下来，先用10取余，累加，在除以10，
//这就就能得到各个位上的数字之和，之后如果和大于9，重复上述步骤，直到小于9，返回最后的值。

int NumRoot(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    while (sum > 9) {
        sum = NumRoot(sum);
    }
    return sum;
}

int main() {
    string num;
    while (cin >> num) {
        int sum = 0;
        for (int i = 0; i < num.size(); ++i) {
            sum += num[i] - '0';
        }
        cout << NumRoot(sum) << endl;;
    }
    return 0;
}
