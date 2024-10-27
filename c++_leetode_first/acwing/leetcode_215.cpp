//
// Created by 11818 on 2024/10/27.
//
// 215. Kth Largest Element in an Array

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

//第一种方法：利用维护一个小根堆
//为什么是小根堆，堆顶元素是堆中最小，那么还在堆中的都比它大，没在堆内的都比它小。
//堆中有k个元素，那么他自然就是第K的最大元素了找最大，用小根

//class Solution {
//public:
//    int findKthLargest(vector<int>& nums, int k) {
//        priority_queue<int,vector<int>,greater<int>> q;//小顶堆
//        for(auto x : nums){
//            q.push(x);
//            if(q.size() > k)    q.pop();
//        }
//        return q.top();
//    }
//};

//第二种方法：快速排序算法
class Solution{
public:
    int solve(vector<int>& nums,int l, int r, int k){
        //k这里面表示的是是第k个大数
        if(r == l)
            return nums[l];
        //为何要取这一步，是因为可能最终要算的那半个区域里面要进行一下这样的同步
        int pivot = nums[l], i = l , j = r;
        while(i < j){
            while(i < j && nums[j] < pivot)  j--;//这个是从大大小排列的
            if(i < j)
                    nums[i++] = nums[j];
            while(i < j && nums[i] > pivot) i++;
            if(i < j)
                    nums[j--] = nums[i];
        }
        if(i + 1 == k)
                return pivot;
        else if(i + 1 > k)
            return solve(nums,l, i - 1,k);
        else
            return solve(nums,i + 1,r,k);
    }
    int findKthLargest(vector<int>& nums, int k){
        int n = nums.size();
        return solve(nums,0,n - 1,k);
    }
};
int main(){
    Solution s;
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout<<s.findKthLargest(nums,k)<<endl;
}


