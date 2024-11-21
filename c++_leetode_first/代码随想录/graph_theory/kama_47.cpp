//
// Created by 11818 on 2024/11/19.
//
//dijkstra算法
//第一步：选源点到哪个节点近且该节点未被访问过
//第二步：该最近节点被标记访问过
//第三步：更新非访问节点到原点的距离(更新minDist数组)
//minDist数组 用来记录 每一个节点距离源点的最小距离
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m, p1, p2, val;
    cin >> n >> m;
    vector<vector<int>> grid(n + 1, vector<int>(n + 1, INT_MAX));
    while (m--) {
        cin >> p1 >> p2 >> val;
        grid[p1][p2] = val;
    }
    int start = 1;
    int end = n;
    //存储从源点到每个节点的最短距离
    vector<int> minDist(n + 1, INT_MAX);
    //记录顶点是否被访问过
    vector<bool> visited(n + 1, false);
    minDist[start] = 0;
    for (int i = 1; i <= n; i++) {
        //遍历所有的节点
        int minVal = INT_MAX;
        int cur = 1;
        //1.选择距离源点最近且未被访问过的点
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && minDist[v] < minVal) {
                minVal = minDist[v];
                cur = v;
            }
        }
        visited[cur] = true;
        for (int v = 1; v <= n; v++) {//v是对应更新的节点
            if (!visited[v] && grid[cur][v] != INT_MAX && minDist[cur] + grid[cur][v] < minDist[v]) {
                minDist[v] = minDist[cur] + grid[cur][v];
            }
        }
    }
    if (minDist[end] == INT_MAX) cout << -1 << endl;
    else
        cout << minDist[end] << endl;
    return 0;
}