//
// Created by 11818 on 2024/12/26.
//

/**
 * kama_54:替换数字
 * 给定一个字符串 s，它包含小写字母和数字字符，请编写一个函数，将字符串中的字母字符保持不变，而将每个数字字符替换为number。
 * 例如，对于输入字符串 "a1b2c3"，函数应该将其转换为 "anumberbnumbercnumber"。
 * input :输入一个字符串 s,s 仅包含小写字母和数字字符。
 * output :打印一个新的字符串，其中每个数字字符都被替换为了number
 *
 * 解题思路：
 *  先计算出来当前的s有多少个数字，然后对应上s开始重构字符串大小
 *  然后利用双指针的方法，一个位于old_s的末尾位置，一个位于new_s
 *  如果old_s位置上是数字的话，new_s开始往前面覆盖，覆盖出一个number之后
 *  如果old_s位置上不是数字的话，new_s直接吸收old_s上的字符串，然后就可以了
 * */
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        int sOldIndex = s.size() - 1;
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            count++;
        }
        s.resize(s.size() + count * 5);
        int sNewIndex = s.size() - 1;
        while (sOldIndex >= 0) {
            if (s[sOldIndex] >= '0' && s[sOldIndex] <= '9') {
                s[sNewIndex--] = 'r';
                s[sNewIndex--] = 'e';
                s[sNewIndex--] = 'b';
                s[sNewIndex--] = 'm';
                s[sNewIndex--] = 'u';
                s[sNewIndex--] = 'n';
            } else {
                s[sNewIndex--] = s[sOldIndex];
            }
            sOldIndex--;
        }
        cout << s << endl;
    }
}