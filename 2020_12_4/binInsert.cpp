// ��m����jλ������n��򼴿�

class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        // write code here
        int ret = n | (m << j);
        return ret;
    }
};