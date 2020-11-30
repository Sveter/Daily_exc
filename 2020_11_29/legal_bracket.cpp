#include <iostream>
#include <string>
using namespace std;

class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        // write code here
        int left = 0;
        for (int i = 0; i < n; i++) {
            if (left == 0)
                if (A[i] == ')')
                    return false;
                else if (A[i] == '(')
                    left++;
                else
                    return false;
            else
                if (A[i] == ')')
                    left--;
                else if (A[i] == '(')
                    left++;
                else
                    return false;
        }
        return true;
    }
};