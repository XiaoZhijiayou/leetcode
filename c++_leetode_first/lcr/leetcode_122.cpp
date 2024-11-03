//
// Created by 11818 on 2024/10/31.
//
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string pathEncryption(string path) {
        string result;
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '.') {
                result += ' ';
            } else {
                result += path[i];
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    string path = "a.aef.qerf.bb";
    cout << s.pathEncryption(path) << endl;
    return 0;
}