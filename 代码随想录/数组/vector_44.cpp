#include <cstdint>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <algorithm>
using namespace std;

int apart_build(vector<vector<int>> &builds) {
    int result = INT32_MAX;
    
    // 计算行和（修正总和计算）
    vector<int> row_sum(builds.size(), 0);
    int total_row = 0;  // 新增总行和变量
    for (int i = 0; i < builds.size(); i++) {
        for (int j = 0; j < builds[i].size(); j++) {
            row_sum[i] += builds[i][j];
        }
        total_row += row_sum[i];  // 累加得到总行和
    }
    
    // 计算列和（修正总和计算）
    vector<int> col_sum(builds[0].size(), 0);
    int total_col = 0;  // 新增总列和变量
    for (int i = 0; i < builds[0].size(); i++) {
        for (int j = 0; j < builds.size(); j++) {
            col_sum[i] += builds[j][i];
        }
        total_col += col_sum[i];  // 累加得到总列和
    }
    
    // 修正分割线计算逻辑
    for (int i = 0; i < row_sum.size(); i++) {  // 遍历所有可能分割点
        int prefix = accumulate(row_sum.begin(), row_sum.begin() + i + 1, 0);
        result = min(result, abs(total_row - 2 * prefix));
    }
    
    for (int i = 0; i < col_sum.size(); i++) {  // 遍历所有可能分割点
        int prefix = accumulate(col_sum.begin(), col_sum.begin() + i + 1, 0);
        result = min(result, abs(total_col - 2 * prefix));
    }
    
    return result;
}

int main() {
    int n = 0;
    int m = 0;
    cin >> n >> m;
    vector<vector<int>> builds(n, vector<int>(m, 0));
    // 正确写法：使用双重循环索引或引用
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> builds[i][j];
        }
    }
    cout << apart_build(builds) << endl; 

    return 0;
}