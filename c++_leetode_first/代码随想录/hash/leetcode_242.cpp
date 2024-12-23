//
// Created by 11818 on 2024/12/22.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for (auto c: s) {
            record[c - 'a']++;
        }
        for (auto c: t) {
            record[c - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution S;
    string s = "anagram";
    string t = "nagaram";
    cout << S.isAnagram(s, t) << endl;
    return 0;
}