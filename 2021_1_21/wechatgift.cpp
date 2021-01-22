//思路：将数组gifts排序，如果有红包的出现的次数超过了一半，那么数组中间的元素的值一定是这个出现了超过一半次数的红包金额
//遍历数组，用count存储中间元素在数组出现的次数，如果超过了一半则说明有，并且这个中间元素就是需要返回的值

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        sort(gifts.begin(), gifts.end());
        int middle = gifts[n / 2];
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (gifts[i] == middle)
                ++count;
        }
        if (count > n / 2)
            return middle;
        else
            return 0;
    }
};