//
// Created by 11818 on 2024/12/22.
//
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    int getNum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> set;
        while (1) {
            int sum = getNum(n);
            if (sum == 1) {
                return true;
            }
            if (set.find(sum) != set.end()) {
                return false;
            } else {
                set.insert(sum);
            }
            n = sum;
        }
    }
};

int main() {
    Solution s;
    int n = 19;
    cout << s.isHappy(n) << endl;
    return 0;
}