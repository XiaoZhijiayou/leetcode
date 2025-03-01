#include <vector>
#include <iostream>
#include <cstdint>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int result = INT32_MAX;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (sum >= target) {
                result = min(result, right - left + 1);
                sum -= nums[left++];
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};

int main() {
    vector<int> nums = {1,2,3,4,5};
    Solution s;
    cout << s.minSubArrayLen(11, nums) << endl;
    return 0;
}