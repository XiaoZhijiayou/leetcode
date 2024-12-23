//
// Created by 11818 on 2024/12/23.
//

/**
 * leetcode 454:四数相加 ||
 * 给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：
 * 0 <= i, j, k, l < n
 * nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 *
 * 解题方法：
 *  首先定义一个unordered_map，key放a和b的两数之和，value放a 和 b的两数之和出现的次数
 *  遍历a b 存放两数之和出现的次数
 *  然后开始遍历c d 两个数组找到 0 -(c + d)在map中是否存在，
 * */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        int result = 0;
        unordered_map<int, int> map;
        for (auto i1: nums1) {
            for (auto i2: nums2) {
                map[i1 + i2]++;
            }
        }
        //开始遍历 3 4
        for (auto i3: nums3) {
            for (auto i4: nums4) {
                int gap = 0 - (i3 + i4);
                if (map.find(gap) != map.end()) {
                    result += map[gap];
                }
            }
        }
        return result;
    }
};