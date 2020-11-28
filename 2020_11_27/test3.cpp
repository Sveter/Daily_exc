#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int StrToInt(string str) {
        int size = str.size();
        int result = 0;
        if (!size) return 0;   //�մ�
        for (int i = (str[0] == '-' || str[0] == '+') ? 1 : 0; i < size; i++) {
            if (str[i] < '0' || str[i]>'9') return 0;  //�м�����ĸ��ֱ�ӷ���0
            result = result * 10 + str[i] - '0';
        }
        return str[0] == '-' ? -result : result;    //Ϊ�����Ļ����븺��
    }
};