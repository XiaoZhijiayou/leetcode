//
// Created by 11818 on 2024/10/26.
//
// Leetcode 3181. 执行操作后字典序最小的最少交换次数||
#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxTotalReward(vector<int> &rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        rewardValues.erase(unique(rewardValues.begin(), rewardValues.end()), rewardValues.end());
        //使用 unique 函数去除 rewardValues 中的重复元素，
        // 然后使用 erase 函数删除重复的部分。这是为了确保每个奖励值是唯一的，避免重复计算
        bitset<100000> f{1};//初始化第 0 位为 1，表示和为 0 是可达的。
        for (int v: rewardValues) {
            int shift = f.size() - v;
            // 左移 shift 再右移 shift，把所有 >= v 的比特位置 0
            // f |= f << shift >> shift << v;
            f |= f << shift >> (shift - v);// 简化上式
        }
        for (int i = rewardValues.back() * 2 - 1;; i--) {
            if (f.test(i)) {
                return i;
            }
        }
    }
};
int main() {
    Solution s;
    vector<int> rewardValues{1, 1, 3, 3};
    cout << s.maxTotalReward(rewardValues) << endl;
    return 0;
}