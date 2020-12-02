#include <iostream>
using namespace std;

/*
* 另类加法
* 思路：
* 而“不带进位的加法”其实就是异或运算，“进位”其实就是只有两个1的时候才会出现，
也就是与运算，只是因为进了一位，所以还要往左移动一位。这样就将两个数相加通过位运
算转换成了不带进位的加法结果和进位相加的问题，反复进行下去，最后只要没有进位了，
相加的结果也就得到了。
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