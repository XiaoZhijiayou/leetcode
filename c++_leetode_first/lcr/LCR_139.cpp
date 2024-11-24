//
// Created by 11818 on 2024/11/24.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> trainingPlan(vector<int> &actions) {
        int i = 0;
        for (int j = 0; j < actions.size(); j++) {
            if (actions[j] & 1) {
                swap(actions[i], actions[j]);
                i++;//慢指针移动
            }
        }
        return actions;
    }
};

int main() {
    Solution s;
    vector<int> actions = {1, 2, 3, 4, 5};
    s.trainingPlan(actions);
    for (auto a: actions) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}