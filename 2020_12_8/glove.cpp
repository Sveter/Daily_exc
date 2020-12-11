#include <iostream>
#include <vector>
using namespace std;

//˼·��������һ���� a1<a2<a3<a4<...<an��ѡ�����ٸ��ܹ���֤����n����ɫ��
//���� sum(a1...an)-a1+1�����Ƹ볲ԭ��
//��������������׺��������ı��ܹ�����n����ɫ�����һ����������ף�
//���� min(leftSum-leftMin+1,rightSum-rightMin+1)�����ȷ���Ժ�
//ֻ��Ҫ����һ�����ѡ��һ�����ܹ���֤������һ����ɫƥ����
//����Ҫע��ĳ����ɫ������Ϊ0�����

class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
        // write code here
        int left_sum = 0, left_min = INT_MAX;
        int right_sum = 0, right_min = INT_MAX;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            // ��߻����ұ�û�е�ʱ����Ҫȫ������(�����)
            if (left[i] * right[i] == 0)
            {
                sum += left[i] + right[i];
            }
            // �ҵ���ߺ��ұ߷ֱ����ٵ���ɫ�������������ܺ�
            else {
                left_sum += left[i];
                right_sum += right[i];
                left_min = min(left[i], left_min);
                right_min = min(right[i], right_min);
            }
        }
        // �ҵ���ߺ��ұ��н�С��ֵ������һ��ֱ����һ���Ϳ��Ա�֤����
        return sum + min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;
    }
};