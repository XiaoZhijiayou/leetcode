//
// Created by 11818 on 2024/10/24.
//
#include <iostream>
using namespace std;
class Solution {
public:
    int hammingWeight(int n) {
        int result = 0;
        for (int i = 0; n != 0; i++) {
            int temp = n & 1;
            if (temp == 1) {
                result++;
            }
            n = n >> 1;
        }
        return result;
    }
};
int main() {
    Solution s;
    int n = 11;
    cout << s.hammingWeight(n) << endl;
    return 0;
}