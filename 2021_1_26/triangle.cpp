#include<iostream>
#include<string>

using namespace std;

//��ÿ�ֿ��ܳ��ֵ�����������жϣ��Ա߽�������ע��

string string_add(string s1, string s2)//���������ַ�����Ӻ�Ľ��
{
    int len1 = s1.size() - 1;//���±�����ַ����ķ��ʣ�����ע��߽�����
    int len2 = s2.size() - 1;
    string res;
    int i, j, t = 0;
    //������һ���ַ��������ͽ���ѭ��
    for (i = len1, j = len2; i >= 0 && j >= 0; i--, j--)
    {
        t += ((s1[i] - '0') + (s2[j] - '0'));
        res = (char)(t % 10 + '0') + res;
        //ע�⣬��鲻����+=����Ϊ���൱���ַ���β�壬ѭ����ѵ�λһֱ������λ����������
        t /= 10;
    }

    while (i >= 0)//�ַ���s1û�з�����
    {
        t += ((s1[i]) - '0');
        res = (char)(t + '0') + res;
        t /= 10;
        i--;
    }

    while (j >= 0)//�ַ���s2û�з�����
    {
        t += ((s2[j]) - '0');
        res = (char)(t + '0') + res;
        t /= 10;
        j--;
    }

    if (t > 0)//ѭ��������t���ܲ�Ϊ0���ü����ж�
        res = (char)(t + '0') + res;

    return res;
}

bool compare(string s1, string s2)//�Ƚ������ַ����Ĵ�С
{
    if (s1.size() > s2.size())
        return true;
    else if (s1.size() < s2.size())
        return false;
    else
        return s1 > s2;
}

int main()
{
    string a, b, c;
    while (cin >> a >> b >> c)
    {
        if (compare(string_add(a, b), c)
            && compare(string_add(b, c), a)
            && compare(string_add(a, c), b))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
