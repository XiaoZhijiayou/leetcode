//
// Created by 11818 on 2024/10/24.
//
//颠倒给定的 32 位无符号整数的二进制位
//做法：
//将整数的二进制的每一位取出来，然后在对应上取高位，每一次取出来之后，依次加到答案的后面
#include <iostream>
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            res = res * 2 + (n >> i & 1);//n >> i 取出第i位的二进制位，&1 取出最低位
            //然后对应res在下次相加的时候就是取高位，所以res * 2
        }
        return res;
    }
};

int main() {
    Solution s;
    std::cout << s.reverseBits(43261596) << std::endl;// 964176192
    return 0;
}