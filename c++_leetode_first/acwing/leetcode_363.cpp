//
// Created by 11818 on 2024/12/4.
//
#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> s;

    int get(int x1, int y1, int x2, int y2) {
        return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
    }

    int maxSumSubmatrix(vector<vector<int>> &w, int K) {
        int n = w.size(), m = w[0].size();
        s = vector<vector<int>>(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + w[i - 1][j - 1];

        int res = INT_MIN;
        for (int i = 1; i <= m; i++)
            for (int j = i; j <= m; j++) {
                set<int> S;
                S.insert(0);
                for (int k = 1; k <= n; k++) {
                    int si = get(1, i, k, j);
                    auto it = S.lower_bound(si - K); /**其中要找到si - sj <= k的的两个值*对应的lower_bound就是找到大于等于si -k的值的最小的那个迭代器对应的值*/
                    if (it != S.end()) res = max(res, si - *it);
                    S.insert(si);
                }
            }

        return res;
    }
};
int main() {
    Solution s;
    vector<vector<int>> matrix = {{1, 0, 1}, {0, -2, 3}};
    int k = 2;
    cout << s.maxSumSubmatrix(matrix, k) << std::endl;
    return 0;
}
