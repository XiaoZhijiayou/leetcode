//
// Created by 11818 on 2024/11/17.
//
#include <iostream>
#include <vector>
using namespace std;
class NumArray {
public:
    vector<int> s;
    NumArray(vector<int> &nums) {
        s.resize(nums.size() + 1);
        for (int i = 1; i <= nums.size(); i++) s[i] = s[i - 1] + nums[i - 1];
    }

    int sumRange(int left, int right) {
        ++left;
        ++right;
        return s[right] - s[left - 1];
    }
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray *obj = new NumArray(nums);
    int left = 1;
    int right = 4;
    int param_1 = obj->sumRange(left, right);
    cout << param_1 << endl;
    return 0;
}