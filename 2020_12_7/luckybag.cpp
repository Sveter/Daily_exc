#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> number(n);
    for (int i = 0; i < n; i++) {
        cin >> number[i];
    }
    sort(number.begin(), number.end());
    int ones = 0;
    while (ones < n and number[ones] == 1) {
        ++ones; // ����1�ĸ���
    }
    if (ones <= 0) { //��1���޽�
        cout << 0 << endl;
        return 0;
    }
    vector<int> prod = { 1 }; //��¼���еĳ˻�
    vector<int> sum = { 0 };  //����
    int pre = 0;
    for (int i = ones; i < n; ++i) {
        int m = sum.size();
        int k = 0;
        if (number[i] == number[i - 1]) {
            //�����ǰһ��һ����û��Ҫ�ظ���ӵ�ǰ��Ĵ���
            k = pre;
        }
        for (; k < m; ++k) {
            //����number[i]�������Ӻ��Ƿ������˵ģ��ȸ���1����������У�
            if (sum[k] + number[i] - prod[k] * number[i] > -ones) {
                prod.push_back(prod[k] * number[i]);//���浱ǰ���ӳ˻�����
                sum.push_back(sum[k] + number[i]);
            }
        }
        pre = m;
    }
    int count = ones > 2 ? ones - 1 : 0;//ֻ��1��ɵ����˴�����
    for (int k = 1; k < sum.size(); ++k) {//ͨ�����벻ͬ������1��ʹ����������
        count += ones + sum[k] - prod[k];
    }
    cout << count << endl;
    return 0;
}
