#include <iostream>
#include <vector>
using namespace std;


class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        // write code here
        int len = board.size();
        //�����
        for (int i = 0; i < len; i++)
        {
            int sum = 0;
            for (int j = 0; j < len; j++)
                sum += board[i][j];
            if (sum == len)
                return true;
        }
        //�����
        for (int i = 0; i < len; i++)
        {
            int sum = 0;
            for (int j = 0; j < len; j++)
                sum += board[j][i];
            if (sum == len)
                return true;
        }
        //������Խ���
        int temp = 0;
        for (int i = 0; i < len; i++)
        {
            temp += board[i][i];
        }
        if (temp == len) return true;

        //��鸱�Խ���
        temp = 0;
        for (int i = 0; i < len; i++)
        {
            temp += board[i][len - i - 1];
        }
        if (temp == len) return true;

        return false;
    }
};