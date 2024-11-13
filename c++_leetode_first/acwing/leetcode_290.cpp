//
// Created by 11818 on 2024/11/13.
//

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> str2ch;
        unordered_map<char, string> ch2str;
        int m = s.length();
        int i = 0;
        for (auto ch: pattern) {
            if (i >= m) {
                return false;
            }//这个是为了保证每个ch都有一个对应位置的string对应上
            int j = i;
            while (j < m && s[j] != ' ') j++;
            const string &temp = s.substr(i, j - i);
            if (str2ch.count(temp) && str2ch[temp] != ch) {
                return false;
            }
            if (ch2str.count(ch) && ch2str[ch] != temp) {
                return false;
            }
            str2ch[temp] = ch;
            ch2str[ch] = temp;
            i = j + 1;
        }
        return i >= m;//这个是为了保证每个string都有一个ch对应上
    }
};
int main() {
    Solution s;
    string pattern = "abba";
    string str = "dog cat cat dog";
    cout << s.wordPattern(pattern, str) << endl;
    return 0;
}