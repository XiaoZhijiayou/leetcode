//
// Created by 11818 on 2024/11/21.
//
//209.长度最小的子数组
//滑动窗口
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int result = INT_MAX;
        int cur_count = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            cur_count += nums[r];               // 增加右边界的值
            while (cur_count >= target) {       // 持续调整左边界
                result = min(result, r - l + 1);// 更新最小长度
                cur_count -= nums[l];           // 减去左边界的值
                l++;                            // 移动左边界
            }
        }
        return result == INT_MAX ? 0 : result;// 如果结果未被更新，返回 0
    }
};

int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    Solution s;
    cout << s.minSubArrayLen(target, nums) << endl;
    return 0;
}
