#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     *  ����λ�϶�����������ż��λ�϶���ż��
     *  ���룺����arr�����ȴ���2
     *  len��arr�ĳ���
     *  ��arr����������λ�϶�����������ż��λ�϶���ż��
     * ˼·��
	 *  ���������±�ֱ�������������λ��ż��λ
	 *  �ڲ�һ�µ�λ��(����λ�Ϸ�������ż��λ�Ϸ�ż��)ͣ����
	 *  �������±궼ͣ����ʱ�Ͷ�����������λ�ý������ټ������Ѱ��ֱ����һ���±굽ĩβ
     */
    void oddInOddEvenInEven(vector<int>& arr, int len) {
        int i = 0, j = 1;
        while (i < len && j < len)
        {
            if (arr[len - 1] % 2 == 0)
            {
                swap(arr[len - 1], arr[i]);
                i += 2;
            }
            else
            {
                swap(arr[len - 1], arr[j]);
                j += 2;
            }
        }
    }
};