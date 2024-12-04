//
// Created by 11818 on 2024/12/1.
//

//345.反转字符串中的元音字母
//利用双指针的算法实现
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string s = "aeiou";
    bool check(char c) {
        return s.find(tolower(c)) != -1;
    }
    string reverseVowels(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            while (i < j && !check(s[i])) i++;
            while (i < j && !check(s[j])) j--;
            swap(s[i], s[j]);
        }
        return s;
    }
};

int main() {
    Solution s;
    string a = "IceCreAm";
    cout << s.reverseVowels(a) << endl;
    return 0;
}