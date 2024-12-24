//
// Created by 11818 on 2024/12/24.
//

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ch[26] = {0};
        for (auto c: magazine) {
            ch[c - 'a']++;
        }
        for (auto c: ransomNote) {
            if (ch[c - 'a'] == 0) {
                return false;
            }
            ch[c - 'a']--;
        }
        return true;
    }
};

int main() {
    string ransomNote = "aa";
    string magazine = "aab";
    Solution s;
    cout << s.canConstruct(ransomNote, magazine) << endl;
    return 0;
}