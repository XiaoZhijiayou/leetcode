//
// Created by 11818 on 2024/12/28.
//

/**
 * leetcode 459:重复的子字符串
 * 给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。
 * 给定的字符串只含有小写英文字母，并且长度不超过10000。
 *
 * 例如：  输入："abab" 输出：true
 *
 * 方法思路：
 *  将字符串s进行拼接，s + s的去头去尾，然后从中找出其中满足s的长串
 * */

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        t.erase(t.begin());
        t.erase(t.end() - 1);
        if (t.find(s) != std::string::npos) return true;
        return false;
    }
};

int main() {
    return 0;
}