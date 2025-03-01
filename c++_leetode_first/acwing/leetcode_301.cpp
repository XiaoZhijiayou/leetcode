//
// Created by 11818 on 2024/11/15.
//
//删除无效括号
//1.左右括号数量相同
//2.任意一个前缀中，左括号数量>=右括号
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') l++;
            if (l == 0 && s[i] == ')') r++;
            else if (s[i] == ')')
                l--;
        }
        dfs(s, 0, l, r);
        return res;
    }
    bool check(string s) {
        int cnt = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') cnt++;
            else if (s[i] == ')')
                cnt--;
            if (cnt < 0) return false;
        }
        return cnt == 0;
    }
    void dfs(string s, int u, int l, int r) {
        if (l == 0 && r == 0) {
            if (check(s)) res.push_back(s);
            return;
        }
        int n = s.length();
        for (int i = u; i < n; i++) {
            if (s[i] != '(' && s[i] != ')') continue;
            if (i == u || s[i] != s[i - 1]) {
                string cur = s;
                cur.erase(i, 1);
                if (s[i] == '(' && l > 0) dfs(cur, i, l - 1, r);
                else if (s[i] == ')' && r > 0)
                    dfs(cur, i, l, r - 1);
            }
        }
    }
};

int main() {
    return 0;
}