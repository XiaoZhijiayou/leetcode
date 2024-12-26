//
// Created by 11818 on 2024/12/26.
//

/**
 * leetcode_151:反转字符串中的单词
 * 给你一个字符串 s ，请你反转字符串中 单词 的顺序
 * 单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
 * 返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
 * 注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。
 *
 * 解题方法：
 *  1.先移除多余的空格
 *  2.将整个字符串反转
 *  3.将每个单词反转
 * */
#include <iostream>
#include <string>
using namespace std;
//class Solution {
//public:
//    void reverse(string &s, int start, int end) {
//        for (int i = start, j = end; i < j; i++, j--) {
//            swap(s[i], s[j]);
//        }
//    }
//    void removeExtraSpaces(string &s) {
//        int slow = 0;
//        for (int i = 0; i < s.size(); i++) {
//            if (s[i] != ' ') {
//                if (slow != 0) s[slow++] = ' ';
//                while (i < s.size() && s[i] != ' ') {
//                    s[slow++] = s[i++];
//                }
//            }
//        }
//        s.resize(slow);
//    }
//    string reverseWords(string s) {
//        removeExtraSpaces(s);
//        reverse(s, 0, s.size() - 1);
//        int start = 0;
//        for (int i = 0; i <= s.size(); i++) {
//            if (i == s.size() || s[i] == ' ') {
//                reverse(s, start, i - 1);
//                start = i + 1;
//            }
//        }
//        return s;
//    }
//};
class Solution {
public:
    void removeExtraSpace(string &s) {
        int oldindex = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                if (oldindex != 0) s[oldindex++] = ' ';
                while (i < s.size() && s[i] != ' ') {
                    s[oldindex++] = s[i++];
                }
            }
        }
        s.resize(oldindex);
    }

    void reverse(string &s, int begin, int end) {
        for (int i = begin, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    string reverseWords(string s) {
        removeExtraSpace(s);
        reverse(s, 0, s.size() - 1);
        int start = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (s[i] == ' ' || i == s.size()) {
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }
};
int main() {
    Solution S;
    string s = "the sky is blue";
    cout << S.reverseWords(s) << endl;
    return 0;
}