//
// Created by 11818 on 2024/10/30.
//
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string getSmallestString(string s) {
        for (int i = 0; i + 1 < s.size(); i++) {
            if (s[i] > s[i + 1] && s[i] % 2 == s[i + 1] % 2) {
                cout << "s[i] = " << static_cast<int>(s[i]) << " s[i+1] = " << static_cast<int>(s[i + 1]) << endl;
                //其中char类型转变成int类型之后他们对应的字符的奇偶性质是一样的
                swap(s[i], s[i + 1]);
                break;
            }
        }
        return s;
    }
};

int main() {
    Solution s;
    string a = "45320";
    cout << s.getSmallestString(a) << endl;
}