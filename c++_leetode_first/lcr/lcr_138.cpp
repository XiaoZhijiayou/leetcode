//
// Created by 11818 on 2024/11/24.
//
/**
 * 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
 * 数值（按顺序）可以分成以下几个部分：
 * 1.若干空格
 * 2.一个 小数 或者 整数
 * 3.（可选）一个 'e' 或 'E' ，后面跟着一个 整数
 * 4.若干空格
 * 小数（按顺序）可以分成以下几个部分：
 * 1.（可选）一个符号字符（'+' 或 '-'）
 * 2.下述格式之一：
    a.至少一位数字，后面跟着一个点 '.'
    b.至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
    c.一个点 '.' ，后面跟着至少一位数字
   3.整数（按顺序）可以分成以下几个部分：
        1.（可选）一个符号字符（'+' 或 '-')
        2.至少一位数字
   整数部分例子：["+100", "5e2", "-123", "3.1416", "-1E-16", "0123"]
   分数值列举：["12e", "1a3.14", "1.2.3", "+-5", "12e+5.4"]
 * */

/**
 * 解题方案：分类讨论
 * 1.首先先去除字符串s首尾的空格
 * 维护下面变量其中：
 *      digit：表示是否出现过数字
 *      dot：表示是否出现过点
 *      e：表示是否出现过e或者E
 * 遍历 s[i,..j]范围内的每个字符，根据字符的类型进行分类讨论：
 * 1.如果当前字符是 + 或者 -，那么该字符必须是第一个有效字符（即空格后的第一个非空字符），
 * 或者该字符的前一个字符必须是 e 或者 E，否则返回 false。
 * 2.如果当前字符是数字，那么我们将 digit 置为 true。
 * 3.如果当前字符是 .，那么该字符之前不能出现过 .或者 e/E，否则返回 false，否则我们将 dot 置为 true。
 * 4.如果当前字符是 e 或者 E，那么该字符之前不能出现过 e/E，并且必须出现过数字，否则返回 false，
 * 否则我们将 e 置为 true，并且将 digit 置为 false，表示 e 之后必须出现数字。
 * 5.如果当前字符是其它字符，那么返回 false。
 *
 * 遍历结束后，我们返回 digit，即是否出现过数字。
 * */
/**
 * LCR138.有效数字
 * */
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool validNumber(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j && s[i] == ' ') {
            ++i;
        }
        while (i <= j && s[j] == ' ') {
            --j;
        }
        if (i > j) {
            return false;
        }
        bool digit = false, dot = false, e = false;
        for (; i <= j; ++i) {
            if (s[i] == '+' || s[i] == '-') {
                if (i && s[i - 1] != ' ' && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } else if (isdigit(s[i])) {
                digit = true;
            } else if (s[i] == '.') {
                if (dot || e) {
                    return false;
                }
                dot = true;
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (!digit || e) {
                    return false;
                }
                e = true;
                digit = false;
            } else {
                return false;
            }
        }
        return digit;
    }
};
int main() {
    Solution s;
    string str = "e";
    cout << s.validNumber(str) << endl;
    return 0;
}