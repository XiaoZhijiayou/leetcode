#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        int left = 0;
        int right = n - 1;
        while (left <= right){
            if (abs(nums[left]) <= abs(nums[right])) {
                res.push_back(nums[right] * nums[right]);
                right--;
            } else {
                res.push_back(nums[left] * nums[left]);
                left++;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main () {
    Solution s;
    vector<int> nums = {-4,-1,0,3,10};
    vector<int> res = s.sortedSquares(nums);
    for (auto num : res) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}