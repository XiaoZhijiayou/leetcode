//
// Created by 11818 on 2024/12/1.
//
//354.俄罗斯套娃信封问题
/**
 * 其实就是一个最长上升子序列的问题：
 * 是一个动态规划问题：
 *      状态表示f[i]:集合：所有以ai结尾的上升子序列的集合  属性：所有集合里面的最大值
 *      状态计算部分：
 *
 * */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//class Solution {
//public:
//    int maxEnvelopes(vector<vector<int>> &w) {
//        int n = w.size();
//        sort(w.begin(), w.end());
//        vector<int> f(n);
//
//        int res = 0;
//        for (int i = 0; i < n; i++) {
//            f[i] = 1;
//            for (int j = 0; j < i; j++) {
//                if (w[j][0] < w[i][0] && w[j][1] < w[i][1]) {
//                    f[i] = max(f[i], f[j] + 1);
//                }
//                res = max(res, f[i]);
//            }
//        }
//        return res;
//    }
//};


class Solution {
public:
    vector<int> bits;
    int m;

    void update(int x, int y) {
        for (; x <= m; x += x & -x)
            bits[x] = max(bits[x], y);
    }

    int query(int x) {
        int tot = 0;
        for (; x; x -= x & -x)
            tot = max(tot, bits[x]);

        return tot;
    }

    int maxEnvelopes(vector<vector<int>> &envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end());

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            a[i] = envelopes[i][1];

        sort(a.begin(), a.end());
        m = unique(a.begin(), a.end()) - a.begin();
        a.resize(m);

        for (int i = 0; i < n; i++)
            envelopes[i][1] = lower_bound(a.begin(), a.end(), envelopes[i][1]) - a.begin() + 1;

        bits.resize(m + 1, 0);

        vector<int> f(n);
        int ans = 0;
        for (int i = 0, j = 0; i < n; i++) {
            if (envelopes[i][0] != envelopes[j][0]) {
                while (j < i) {
                    update(envelopes[j][1], f[j]);
                    j++;
                }
            }
            f[i] = query(envelopes[i][1] - 1) + 1;
            ans = max(ans, f[i]);
        }

        return ans;
    }
};

int main() {
    std::vector<vector<int>> envelopes = {{5, 4},
                                          {6, 4},
                                          {6, 7},
                                          {2, 3}};
    Solution s;
    cout << s.maxEnvelopes(envelopes) << std::endl;
    return 0;
}