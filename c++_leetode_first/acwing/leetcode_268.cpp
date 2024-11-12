//
// Created by 11818 on 2024/11/12.
//
//268.缺失数字

#include <iostream>
#include <vector>
using namespace  std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //算出来0-n的总和是多少
        int n = nums.size();
        int count = n * (n + 1) * 0.5;
        int cur_count = 0;
        for(auto i : nums){
            cur_count += i;
        }
        return (count - cur_count);
    }
};
int main(){
    Solution s;
    vector<int> nums = {3,0,1};
    cout << s.missingNumber(nums) << endl;
    return 0;

}