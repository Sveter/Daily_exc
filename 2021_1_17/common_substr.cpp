#include <iostream>
#include <string>
using namespace std;

//思路：动态规划。dp[i][j] 记录短字符串 s1 前 i 个字符和长字符串 s2 前 j 个字符的最长子串的长度，
//初始化所有值为 0。当 s1[i-1] = s2[j-1]时，dp[i][j] = dp[i-1][j-1]+1，
//注意要使用一个额外的值 start 来记录最长子串在短字符串 s1 中出现的起始位置和 maxlen记录当前最长子串的长度，
//当dp[i][j] > maxlen 时 start = i-dp[i][j]；档s1[i-1] != s2[j-1]时不需要任何操作，这样dp[i][j]就是默认值 0。

string maxCommonSubstr(string s1, string s2)
{
    string s3 = (s1.length() <= s2.length())?s1:s2;
    string s4 = (s1.length() <= s2.length())?s2:s1;
    int m = s3.length();
    int n = s4.length();
    int **dp = new int*[m+1];
    for(int i = 0; i < m+1; i++)
    {
        dp[i] = new int[n+1];
        for(int j = 0; j < n+1; j++)
            dp[i][j] = 0;
    }
    int start = 0, maxlen = 0;
    for(int i = 1; i < m+1; i++)
    {
        for(int j = 1; j < n+1; j++)
        {
            if(s3[i-1] == s4[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
                if(dp[i][j] > maxlen)
                {
                    maxlen = dp[i][j];
                    start = i - maxlen;
                }
            }
        }
    }
    for(int i = 0; i < m+1; i++)
    {
        delete dp[i];
        dp[i] = 0;
    }
    delete [] dp;
    dp = 0;
    return s3.substr(start, maxlen);
}

void test1()
{
    string s1, s2;
    while(cin >> s1 >> s2)
    {
        cout << maxCommonSubstr(s1, s2) << endl;
    }
}

int main()
{
    test1();
    return 0;
}
