//
// Created by 11818 on 2024/11/24.
//
//'.' 匹配任意单个字符
//'*' 匹配零个或多个前面的那一个元素。
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool articleMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        auto matches = [&](int i, int j) {
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] |= dp[i][j - 2];
                    if (matches(i, j - 1)) {
                        dp[i][j] |= dp[i - 1][j];
                    }
                } else {
                    if (matches(i, j)) {
                        dp[i][j] |= dp[i - 1][j - 1];
                    }
                }
            }
        }
        return dp[n][m];
    }
};

//其中dp[i][j]表示s的前i个字符与p的前j个字符是否能够匹配。
//1.如果i 和 j 对应的都是小写字母且相同就直接f[i][j] = f[i-1][j-1]
//2.如果j字符是*表示我们可以对p的j-1个字符匹配任意自然次数，匹配0次情况下，我们有f[i][j]=f[i][j−2]
//还有多种次数下，有两种情况：1.匹配s末尾的一个字符，该字符被扔掉，而该组合还可以继续进行匹配 f[i][j] = f[i-1][j]如果s[i][j-1]相互匹配的话
//                       2.不匹配字符，该组合直接扔掉，不在进行匹配
//在任意情况下，只要p[j]为‘.’，就一定可以匹配成功s中的任意一个小写字母
int main() {
    Solution s;
    string article = "aa";
    string input = "a";
    cout << s.articleMatch(article, input) << endl;
    return 0;
}