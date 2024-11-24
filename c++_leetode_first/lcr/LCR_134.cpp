//
// Created by 11818 on 2024/11/7.
//
/**
 * 采用递归+快速幂思想
 * x-> x^2 -> x^4 -> x^8 .....
 * */
#include <iostream>
using namespace std;
class Solution {
public:
    double quickMul(double x, long long N) {
        if (N == 0) {
            return 1.0;
        }
        double y = quickMul(x, N / 2);
        return N % 2 == 0 ? y * y : y * y * x;
    }
    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};

int main() {
    Solution s;
    double x = 2.00000;
    int n = 10;
    cout << s.quickMul(x, n) << endl;
}