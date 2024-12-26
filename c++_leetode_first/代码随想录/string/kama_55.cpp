//
// Created by 11818 on 2024/12/26.
//

/**
 * kama_55:右旋字符串
 * 字符串的右旋转操作是把字符串尾部的若干个字符转移到字符串的前面。
 * 给定一个字符串 s 和一个正整数 k，请编写一个函数，将字符串中的后面 k 个字符移到字符串的前面，实现字符串的右旋转操作。
 * 例如，对于输入字符串 "abcdefg" 和整数 2，函数应该将其转换为 "fgabcde"。
 *
 *
 * 方法：1.先将整体进行反转
 *      2.然后这两个部分开始依次反转，这个分段是利用k进行决定的
 * */

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int len = s.size();
    reverse(s.begin(), s.end());
    reverse(s.begin(), s.begin() + n);
    reverse(s.begin() + n, s.end());
    cout << s << endl;
    return 0;
}