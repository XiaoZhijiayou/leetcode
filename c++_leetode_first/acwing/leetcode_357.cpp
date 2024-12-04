//
// Created by 11818 on 2024/12/4.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        n = min(10, n);//因为大于10的话就一定没有每位数都不想等的情况了
        if (n == 0) return 1;
        vector<int> f(n + 1);
        f[1] = 9;
        for (int i = 2; i <= n; i++) {
            f[i] = f[i - 1] * (11 - i);
        }//例如有三个位置 就是9*9*8
        int res = 1;
        for (int i = 1; i <= n; i++) {
            res += f[i];
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.countNumbersWithUniqueDigits(2) << std::endl;
    return 0;
}
