//
// Created by 11818 on 2024/11/23.
//
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        string res;
        int i = 0, j = 0;
        while (i < n || j < m) {
            if (i < n) {
                res.push_back(word1[i]);
                ++i;
            }
            if (j < m) {
                res.push_back(word2[j]);
                ++j;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    string word = "abc";
    string word1 = "pqr";
    cout << s.mergeAlternately(word, word1) << endl;
    return 0;
}