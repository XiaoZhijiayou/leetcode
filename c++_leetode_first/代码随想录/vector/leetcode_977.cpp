//
// Created by 11818 on 2024/11/21.
//
//977.有序数组的平方
//双指针的方法
//因为这是一个有序的数组，只是会有负数，所以要两个都在一边
//这个是最大的都在两边分布，所以答案赋值的时候是从最后往前进行赋值的
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int> &nums) {
        vector<int> result(nums.size(), 0);
        int left = 0, right = nums.size() - 1;
        int result_index = nums.size() - 1;
        while (left <= right) {
            if (abs(nums[left]) > abs(nums[right])) {
                result[result_index] = nums[left] * nums[left];
                left++;
                result_index--;
            } else {
                result[result_index] = nums[right] * nums[right];
                right--;
                result_index--;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-4, -1, 0, 3, 10};
    auto result = s.sortedSquares(nums);
    for (auto val: result) {
        cout << val << "  ";
    }
    cout << endl;
    return 0;
}