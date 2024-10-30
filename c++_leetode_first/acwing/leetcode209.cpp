//
// Created by 11818 on 2024/10/26.
//
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //滑动窗口
    //    int minSubArrayLen(int target, vector<int>& nums) {
    //        int result = INT_MAX;
    //        int currentSum = 0;
    //        int left = 0;
    //        int subArrayLen = 0;
    //        for(int right = 0;  right < nums.size();right++){
    //            currentSum += nums[right];
    //            while(currentSum >= target) {
    //                subArrayLen = (right - left + 1);
    //                result = min(subArrayLen, result);
    //                currentSum -= nums[left];
    //                left++;
    //            }
    //        }
    //        if(result == INT_MAX)
    //            return 0;
    //        return result;
    //    }
    //快慢指针
    int minSubArrayLen(int target, vector<int> &nums) {
        const int n = nums.size();
        int ans = INT_MAX, curr_sum = 0;
        for (int fast = 0, slow = 0; fast < n; fast++) {
            curr_sum += nums[fast];
            while (curr_sum >= target) {
                ans = min(ans, fast - slow + 1);
                curr_sum -= nums[slow];
                slow++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
    //其实我感觉快慢指针和滑动窗口的思路是一样的
    //其实统一的思路就是保持这个窗口是连续的，然后移动窗口的左右边界，使得窗口内的和尽可能的小
};
int main() {
    Solution s;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    cout << s.minSubArrayLen(target, nums) << endl;
    return 0;
}