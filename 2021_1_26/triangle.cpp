#include<iostream>
#include<string>

using namespace std;

//把每种可能出现的情况都加以判断，对边界条件多注意

string string_add(string s1, string s2)//返回两个字符串相加后的结果
{
    int len1 = s1.size() - 1;//用下标进行字符串的访问，必须注意边界条件
    int len2 = s2.size() - 1;
    string res;
    int i, j, t = 0;
    //当任意一个字符串结束就结束循环
    for (i = len1, j = len2; i >= 0 && j >= 0; i--, j--)
    {
        t += ((s1[i] - '0') + (s2[j] - '0'));
        res = (char)(t % 10 + '0') + res;
        //注意，这块不能用+=，因为这相当于字符的尾插，循环会把低位一直顶到高位，结果会出错
        t /= 10;
    }

    while (i >= 0)//字符串s1没有访问完
    {
        t += ((s1[i]) - '0');
        res = (char)(t + '0') + res;
        t /= 10;
        i--;
    }

    while (j >= 0)//字符串s2没有访问完
    {
        t += ((s2[j]) - '0');
        res = (char)(t + '0') + res;
        t /= 10;
        j--;
    }

    if (t > 0)//循环结束后t可能不为0，得加以判断
        res = (char)(t + '0') + res;

    return res;
}

bool compare(string s1, string s2)//比较两个字符串的大小
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
