//
// Created by 11818 on 2024/12/5.
//
/**
 * 372.超级次方：快速幂算法
 *  你的任务是计算 ab 对 1337 取模，a 是一个正整数，b 是一个非常大的正整数且会以数组形式给出。
 *          其中一个重要的公式：(a*b) mod c = (a mod c) * (b mod c) mod c
 *          所以这里面需要一直对这个进行取模操作
 * */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    const int p = 1337;
    int qmi(int a, int b) {
        a %= p;
        int res = 1;
        while (b) {
            if (b & 1) res = res * a % p;
            a = a * a % p;
            b >>= 1;
        }
        return res;
    }//这是一个快速幂运算方法
    int superPow(int a, vector<int> &b) {
        if (b.empty()) return 1;
        int k = b.back();
        b.pop_back();
        return qmi(superPow(a, b), 10) * qmi(a, k) % p;
    }
};
int main() {
    Solution s;
    vector<int> b = {2, 0, 0};
    int a = 2147483647;
    cout << s.superPow(a, b) << endl;
}