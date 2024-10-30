//
// Created by 11818 on 2024/10/24.
//
// 205. 同构字符串
// 给定两个字符串 s 和 t，判断它们是否是同构的。
// 如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
// 所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。
//
// 示例 1:
//
// 输入: s = "egg", t = "add"
// 输出: true
//
// 示例 2:
//
// 输入: s = "foo", t = "bar"
// 输出: false
//
// 示例 3:
//
// 输入: s = "paper", t = "title"
// 输出: true
//
// 说明:
// 你可以假设 s 和 t 具有相同的长度。
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> st, ts;
        if (s.size() != t.size()) return false;
        for (int i = 0; i < s.size(); i++) {
            if (st.find(s[i]) == st.end() && ts.find(t[i]) == ts.end()) {
                st[s[i]] = t[i];
                ts[t[i]] = s[i];
            } else if (st[s[i]] != t[i] || ts[t[i]] != s[i]) {// 出现冲突
                return false;
            }
        }
        return true;
    }
};//这个相互绑定的映射是为了保证s和t之间的映射关系只能是一一对应的关系，
// 就是一个s的字符只能对应上一个t的固定的字符
//必须之间相互绑定上
int main() {
    Solution s;
    string s1 = "egg";
    string t1 = "add";
    cout << s.isIsomorphic(s1, t1) << endl;
    string s2 = "foo";
    string t2 = "bar";
    cout << s.isIsomorphic(s2, t2) << endl;
    string s3 = "paper";
    string t3 = "title";
    cout << s.isIsomorphic(s3, t3) << endl;
    return 0;
}