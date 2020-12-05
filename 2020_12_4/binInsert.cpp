// 将m左移j位，再与n相或即可

class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        // write code here
        int ret = n | (m << j);
        return ret;
    }
};