//
// Created by 11818 on 2024/12/5.
//

/**
 *  373.查找和最小的K对数字
 * 给定两个以 非递减顺序排列 的整数数组 nums1 和 nums2 , 以及一个整数 k 。
 * 定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2
 * 请找到和最小的 k 个数对 (u1,v1),  (u2,v2)  ...  (uk,vk)
 *
 * 考察点：多路归并算法
 *
 * */


#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    typedef vector<int> VI;
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        if (nums1.empty() || nums2.empty()) return {};
        int n = nums1.size(), m = nums2.size();
        priority_queue<VI, vector<VI>, greater<VI>> heap;
        for (int i = 0; i < m; i++) { heap.push({nums2[i] + nums1[0], 0, i}); }//先把每一行最小的加入堆内去。
        vector<VI> res;
        while (k-- && heap.size()) {
            auto t = heap.top();
            heap.pop();
            res.push_back({nums1[t[1]], nums2[t[2]]});
            if (t[1] + 1 < n) heap.push({nums1[t[1] + 1] + nums2[t[2]], t[1] + 1, t[2]});//如果取的是当前的行，取完之后需要将这一行的后一个数继续加进去
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 7, 11}, nums2 = {2, 4, 6};
    int k = 3;
    vector<vector<int>> result = s.kSmallestPairs(nums1, nums2, k);
    return 0;
}