//
// Created by 11818 on 2024/11/9.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0,right = nums.size();
        while(left < right){
            int middle = (left + right) >> 1;
            if(nums[middle] < target){
                left = middle + 1;
            }else if(nums[middle] > target){
                right = middle;
            }else{
                return middle;
            }
        }
        return -1;
    }
};
//这个区间搜索范围是左闭右开

int main(){
    Solution s;
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    cout << s.search(nums,target) << endl;
    return 0;
}