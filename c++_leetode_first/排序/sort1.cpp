//
// Created by 11818 on 2024/10/24.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//快排
int quickSort(vector<int>& nums, int left, int right){
    int mid = nums[left];
    while(left < right){
        while(left < right && nums[right] >= mid) right--;
        nums[left] = nums[right];
        while(left < right && nums[left] < mid) left++;
        nums[right] = nums[left];
    }
    nums[left] = mid;
    return left;
}
void quickSort(vector<int>& nums){
    int mid = quickSort(nums, 0, nums.size()-1);
    quickSort(nums, 0, mid-1);
    quickSort(nums, mid+1, nums.size()-1);
}
//冒泡排序
void maopaoSort(vector<int>& nums){
    int n = nums.size();
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n - i - 1 ; j++){
            if(nums[j] > nums[j+1]){
                swap(nums[j], nums[j+1]);
            }
        }
    }
}
//选择排序
void xuanzeSort(vector<int>& nums){
    int n = nums.size();
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n - 1; j++){
            if(nums[i] > nums[j]){
                swap(nums[i], nums[j]);
            }
        }
    }
}


int main(){
    vector<int> nums = {5, 3, 8, 4, 2, 7, 1, 6};
    xuanzeSort(nums);
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}

