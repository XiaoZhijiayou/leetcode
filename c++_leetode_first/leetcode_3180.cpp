//
// Created by 11818 on 2024/10/26.
//
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxTotalReward(vector<int> &rewardValues) {
        //记 rewardValues 的最大值为 m，因为最后一次操作前的总奖励一定小于等于 m−1，
        //所以可获得的最大总奖励小于等于 2m−1。
        //假设上一次操作选择的奖励值为 x 1​，那么执行操作后的总奖励 x≥x1
        //根据题意，后面任一操作选择的奖励值x2 一定都大于 x，从而有 x2>x1，
        //因此执行的操作是按照奖励值单调递增的。
        //所有先要将rewardValues数组从小往大排列。
        sort(rewardValues.begin(), rewardValues.end());
        int m = rewardValues.back();
        vector<int> dp(2 * m);//这个是为了把最大的值表示出来
        //使用dp[k]表示奖励K是否可以获得，初始dp[0]=1，表示不执行任何操作获得总奖励0.
        //然后我们对rewardValues进行遍历，当前值为x，然后对于k属于x到2x-1进行去枚举利用倒叙去枚举
        //为何利用后续，就是为了防止利用上这次处理之后的数据
        dp[0] = 1;//1表示可以取到，0表示取不到
        for (auto x: rewardValues) {
            for (int k = 2 * x - 1; k >= x; k--) {
                if (dp[k - x])
                    dp[k] = 1;
            }
        }
        int res = 0;
        for (int i = 0; i < dp.size(); i++) {
            if (dp[i]) {
                res = i;//表示如果dp[i]取1的话就直接拿下，res进行修改
            }
        }
        return res;
    }
};
int main() {
    Solution s;
    vector<int> rewardValues{1, 1, 3, 3};//4
    cout << s.maxTotalReward(rewardValues) << endl;
    return 0;
}