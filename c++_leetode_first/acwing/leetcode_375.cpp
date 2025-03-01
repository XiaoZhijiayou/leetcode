//
// Created by 11818 on 2024/12/6.
//
/**
 * 375.猜数字大小||
 * 我们正在玩一个猜数游戏，游戏规则如下
 * 1.我从 1 到 n 之间选择一个数字。
 * 2.你来猜我选了哪个数字。
 * 3.如果你猜到正确的数字，就会 赢得游戏 。
 * 4. 如果你猜错了，那么我会告诉你，我选的数字比你的 更大或者更小 ，并且你需要继续猜数。
 * 5.每当你猜了数字 x 并且猜错了的时候，你需要支付金额为 x 的现金。如果你花光了钱，就会 输掉游戏 。
 * 给你一个特定的数字 n ，返回能够 确保你获胜 的最小现金数，不管我选择那个数字 。
 * 这个确保获胜的意思就是，在你所选择的路径是最坏的路径的情况下依然能够取胜，所以对于其中的路径选择部分应该选择最大的那一边去做，
 * 这也就是为何用:max(f[i][k - 1], f[k + 1][j]) + k 的原因
 * 其中这道题目的解法是利用DP的思想去做的，
 *          开始先遍历一个选取的长度 ，然后起点从1开始遍历到n 终点的话就是起点 + len - 1就是终点，然后确定i j 内的最小现金数量
 *          其中f[i][j] = min(f[i][j], max(f[i][k - 1], f[k + 1][j]) + k)
* */
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> f(n + 2, vector<int>(n + 2));
        for (int len = 2; len <= n; len++) {
            for (int i = 1; i + len - 1 <= n; i++) {
                int j = i + len - 1;
                f[i][j] = INT_MAX;
                for (int k = i; k <= j; k++)
                    f[i][j] = min(f[i][j], max(f[i][k - 1], f[k + 1][j]) + k);
            }
        }
        return f[1][n];
    }
};

int main() {
    Solution s;
    int n = 10;
    cout << s.getMoneyAmount(n) << endl;
    return 0;
}