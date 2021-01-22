//˼·��������gifts��������к���ĳ��ֵĴ���������һ�룬��ô�����м��Ԫ�ص�ֵһ������������˳���һ������ĺ�����
//�������飬��count�洢�м�Ԫ����������ֵĴ��������������һ����˵���У���������м�Ԫ�ؾ�����Ҫ���ص�ֵ

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        sort(gifts.begin(), gifts.end());
        int middle = gifts[n / 2];
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (gifts[i] == middle)
                ++count;
        }
        if (count > n / 2)
            return middle;
        else
            return 0;
    }
};