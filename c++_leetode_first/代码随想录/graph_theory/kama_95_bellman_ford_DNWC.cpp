//
// Created by 11818 on 2024/11/20.
//
//在 bellman_ford 算法中，松弛 n-1 次所有的边 就可以求得 起点到任何节点的最短路径，
// 松弛 n 次以上，minDist数组（记录起到到其他节点的最短距离）中的结果也不会有改变
//kama 95.城市间货物运输||
#include <iostream>
#include <list>
#include <vector>
#include <climits>
using namespace std;
int main() {
    int n, m, p1, p2, val;
    cin >> n >> m;
    vector<vector<int>> grid;
    for (int i = 0; i < m; i++) {
        cin >> p1 >> p2 >> val;
        grid.push_back({p1, p2, val});
    }
    int start = 1;
    int end = n;
    vector<int> minDist(n + 1, INT_MAX);
    minDist[start] = 0;
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        for (auto &side: grid) {
            int from = side[0];
            int to = side[1];
            int price = side[2];
            if (i < n) {
                if (minDist[from] != INT_MAX && minDist[to] > minDist[from] + price) minDist[to] = minDist[from] + price;
            } else {
                if (minDist[from] != INT_MAX && minDist[to] > minDist[from] + price) flag = true;
            }
        }
    }
    if (flag) cout << "circle" << endl;
    else if (minDist[end] == INT_MAX) {
        cout << "unconnceted" << endl;
    } else {
        cout << minDist[end] << endl;
    }
    return 0;
}