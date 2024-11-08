//
// Created by 11818 on 2024/11/7.
//
#include <iostream>
using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t cur = n;
        int result = 0;
        while(cur){
            if(cur % 2 == 1)    result++;
            cur /= 2;
        }
        return result;
    }
};
int main(){

    uint32_t n = 4294967293;
    Solution s;
    cout << s.hammingWeight(n) << endl;
    return 0;
}