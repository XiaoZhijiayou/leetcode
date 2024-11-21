//
// Created by 11818 on 2024/11/21.
//
//27.移除元素
//利用上快慢指针的形式
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int slow = 0, fast = 0;
        for (; fast < nums.size(); fast++) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};
int main() {
    Solution s;
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    cout << s.removeElement(nums, val) << endl;
    return 0;
}