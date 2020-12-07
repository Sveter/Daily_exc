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
        ++ones; // 计算1的个数
    }
    if (ones <= 0) { //无1则无解
        cout << 0 << endl;
        return 0;
    }
    vector<int> prod = { 1 }; //记录可行的乘积
    vector<int> sum = { 0 };  //及和
    int pre = 0;
    for (int i = ones; i < n; ++i) {
        int m = sum.size();
        int k = 0;
        if (number[i] == number[i - 1]) {
            //如果与前一数一样就没必要重复添加到前面的袋子
            k = pre;
        }
        for (; k < m; ++k) {
            //加入number[i]到各袋子后，是否是幸运的（比负的1的数量多就行）
            if (sum[k] + number[i] - prod[k] * number[i] > -ones) {
                prod.push_back(prod[k] * number[i]);//保存当前袋子乘积及和
                sum.push_back(sum[k] + number[i]);
            }
        }
        pre = m;
    }
    int count = ones > 2 ? ones - 1 : 0;//只有1组成的幸运袋子数
    for (int k = 1; k < sum.size(); ++k) {//通过加入不同数量的1以使各袋子幸运
        count += ones + sum[k] - prod[k];
    }
    cout << count << endl;
    return 0;
}
