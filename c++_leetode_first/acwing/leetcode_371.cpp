//
// Created by 11818 on 2024/12/5.
//
/**
 * 371.两整数之和
 * 给你两个整数 a 和 b ，不使用 运算符 + 和 - ，计算并返回两整数之和。
 *          异或运算就是不进位的加法  所以加法就是 异或运算加上进位
 *          进位操作就是看哪些位有进位就是1&1就是进位 (a&b) << 1就是进位操作
 *          所以 a + b = (a&b) << 1 +(a^b) = a + b
 *          这个里面还是有加法操作，所以还是不可以的
 * */
#include <iostream>
using namespace std;
class Solution {
public:
    int getSum(int a, int b) {
        if (!a) return b;
        int sum = a ^ b;
        int carry = (unsigned) (a & b) << 1;
        return getSum(carry, sum);
    }
};
int main() {
    Solution s;
    cout << s.getSum(1, 2) << endl;
    return 0;
}