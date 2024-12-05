//
// Created by 11818 on 2024/12/5.
//
/**
 * 368.最大整除子集
 * 1.先整理出来f数组,其中f[i] 表示在i之前的是多大的一个整除子集
 * 2.然后记下最大的整数子集的下标 k
 * 3.然后开始利用k去寻找整体的最大整除子集
 *      利用nums[k] % nums[i] == 0 && f[k] == f[i] + 1
 *      然后更新k = i
 *      然后继续寻找就可以了
 * */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        int n = nums.size();
        vector<int> f(n);
        sort(nums.begin(), nums.end());
        int k = 0;
        for (int i = 0; i < n; i++) {
            f[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0)
                    f[i] = max(f[i], f[j] + 1);
                if (f[k] < f[i]) k = i;
            }
        }
        vector<int> res;
        while (true) {
            res.push_back(nums[k]);
            if (f[k] == 1) break;
            for (int i = 0; i < k; i++) {
                if (nums[k] % nums[i] == 0 && f[k] == f[i] + 1) {
                    k = i;
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<int> result = s.largestDivisibleSubset(nums);
    return 0;
}