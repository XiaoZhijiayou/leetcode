#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        int fast = 0;
        while (fast < nums.size() - 1) {
            if (nums[fast] != val) {
                fast++;
                slow++;
            }else {
                fast++;
            }
            nums[slow] = nums[fast];
        }
        return slow;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3,2,2,3};
    cout << s.removeElement(nums, 3) << endl;
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}