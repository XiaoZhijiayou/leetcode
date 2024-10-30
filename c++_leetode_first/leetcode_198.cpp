//
// Created by 11818 on 2024/10/24.
//

//你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，
// 影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
// 如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//给定一个代表每个房屋存放金额的非负整数数组，计算你不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
#include <iostream>
#include <vector>

using namespace std;
//这里面就需要用到dp的思想，f[i]表示偷盗第i个房屋的最大收益，
//g[i]表示不偷盗第i个房屋的最大收益，则有如下递推式：
//递归表达式就是f[i] = g[i-1] + nums[i]，g[i] = max(f[i-1], g[i-1])
//即偷盗第i个房屋的最大收益等于不偷盗第i-1个房屋的最大收益加上第i个房屋的金额，
//不偷盗第i个房屋的最大收益等于不偷盗第i-1个房屋的最大收益。
//最后返回max(f[n-1], g[n-1])即可。
class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<int> f(n, 0), g(n, 0);
        f[0] = nums[0];
        g[0] = 0;
        for (int i = 1; i < n; i++) {
            f[i] = g[i - 1] + nums[i];
            g[i] = max(f[i - 1], g[i - 1]);
        }
        return max(f[n - 1], g[n - 1]);
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1};
    Solution s;
    cout << s.rob(nums) << endl;
    return 0;
}