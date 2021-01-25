#include<iostream>
#include<string>
using namespace std;

// ���ڿ�����������ֹ�������string��ʾ�������ͣ�֮�����������н������λ�ϵ�����������Σ�
//������Ҳ��1000*9=9000,֮����������int�͵����ݱ�ʾ��������������10ȡ�࣬�ۼӣ��ڳ���10��
//��;��ܵõ�����λ�ϵ�����֮�ͣ�֮������ʹ���9���ظ��������裬ֱ��С��9����������ֵ��

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
