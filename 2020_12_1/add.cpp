#include <iostream>
using namespace std;

/*
* ����ӷ�
* ˼·��
* ����������λ�ļӷ�����ʵ����������㣬����λ����ʵ����ֻ������1��ʱ��Ż���֣�
Ҳ���������㣬ֻ����Ϊ����һλ�����Ի�Ҫ�����ƶ�һλ�������ͽ����������ͨ��λ��
��ת�����˲�����λ�ļӷ�����ͽ�λ��ӵ����⣬����������ȥ�����ֻҪû�н�λ�ˣ�
��ӵĽ��Ҳ�͵õ��ˡ�
*/

class UnusualAdd {
public:
    int addAB(int A, int B) {
        // write code here
        while (B != 0) {
            int t = A ^ B;
            B = (A & B) << 1;
            A = t;
        }
    }
};