//
// Created by 11818 on 2024/10/31.
//
#include <iostream>
#include <vector>
using namespace std;
//第一种指数级别的算法时间复杂度
class Solution {
public:
    //    int fib(int n) {
    //        if(n == 0)
    //            return 0;
    //        else if(n == 1)
    //            return 1;
    //        //其他形式
    //        return fib(n - 1) + fib(n - 2);
    //    }
    //第二种：动态规划:这种算法复杂度就是简单的On的算法复杂度
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i < dp.size(); i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
//这是题目要求部分
//class Solution {
//public:
//    int fib(int n) {
//        const int MOD = 1000000007;
//        if (n == 0) return 0;
//        if (n == 1) return 1;
//
//        long long a = 0;
//        long long b = 1;
//
//        for (int i = 2; i <= n; i++) {
//            long long c = (a + b) % MOD; // 每次相加后取模
//            a = b;
//            b = c;
//        }
//
//        return b;
//    }
//};

int main() {
    Solution s;
    cout << s.fib(4) << endl;
    return 0;
}
