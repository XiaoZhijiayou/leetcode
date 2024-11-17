//
// Created by 11818 on 2024/11/17.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string add(string x, string y) {
        vector<int> A, B, C;
        for (int i = x.size() - 1; i >= 0; i--) A.push_back(x[i] - '0');
        for (int i = y.size() - 1; i >= 0; i--) B.push_back(y[i] - '0');
        for (int i = 0, t = 0; i < A.size() || i < B.size() || t; i++) {
            if (i < A.size()) t += A[i];
            if (i < B.size()) t += B[i];
            C.push_back(t % 10);
            t /= 10;
        }
        string z;
        for (int i = C.size() - 1; i >= 0; i--) {
            z += to_string(C[i]);
        }
        return z;
    }
    bool isAdditiveNumber(string num) {
        for (int i = 0; i < num.size(); i++)
            for (int j = i + 1; j + 1 < num.size(); j++) {
                int a = -1, b = i, c = j;//其中a表示第一个数的开头位置的前一个，b是第二个数的开头位置的前一个，c是第三个数的开头位置的前一个
                while (true) {
                    if (b - a > 1 && num[a + 1] == '0' || c - b > 1 && num[b + 1] == '0') break;//有前导零的
                    auto x = num.substr(a + 1, b - a), y = num.substr(b + 1, c - b);
                    auto z = add(x, y);
                    if (num.substr(c + 1, z.size()) != z) break;//下一个数不匹配
                    a = b, b = c, c += z.size();
                    if (c + 1 == num.size()) return true;
                }
            }
        return false;
    }
};
//对于第一个数a来说就是：0-i部分 对于第二个数b来说就是 i + 1 到j部分  c就是从j + 1开始
int main() {
    Solution s;
    string num = "199100199";
    cout << s.isAdditiveNumber(num) << endl;
    return 0;
}
