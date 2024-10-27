//
// Created by 11818 on 2024/9/19.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2){
            return n;
        }
        int slow = 2, fast = 2;
        while(fast < n){
            if(nums[slow - 2] != nums[fast]){
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};

int main(){
    vector<int> nums = {1,1,1,2,2,3};
    Solution s;
    int res = s.removeDuplicates(nums);
    for(int i = 0; i < res; ++i){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}