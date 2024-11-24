//
// Created by 11818 on 2024/11/23.
//
//对于字符串 s 和 t，只有在 s = t + t + t + ... + t + t（t 自身连接 1 次或多次）时，
// 我们才认定 “t 能除尽 s”。
//给定两个字符串 str1 和 str2 。返回 最长字符串 x，要求满足 x 能除尽 str1 且 x 能除尽 str2 。
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool check(string t, string s) {
        int lenx = (int) s.length() / (int) t.length();
        string ans = "";
        for (int i = 1; i <= lenx; ++i) {
            ans = ans + t;
        }
        return ans == s;
    }
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.length();
        int len2 = str2.length();
        for (int i = min(len2, len1); i >= 1; i--) {
            if (len1 % i == 0 && len2 % i == 0) {
                string x = str1.substr(0, i);
                if (check(x, str1) && check(x, str2)) return x;
            }
        }
        return "";
    }
};
int main() {
    string str1 = "ABCABC";
    string str2 = "ABC";
    Solution s;
    cout << s.gcdOfStrings(str1, str2) << endl;
    return 0;
}