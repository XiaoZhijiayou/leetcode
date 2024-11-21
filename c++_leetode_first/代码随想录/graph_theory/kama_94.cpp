//
// Created by 11818 on 2024/11/20.
//
//94.城市间货物运输|
//Bellman_ford算法：对所有的边进行松弛n-1次操作(n位节点数量)，从而求得目标最短路
//经典的带负权值的单源最短路问题
#include <iostream>
#include <list>
#include <vector>
using namespace std;
int main() {
    int n, m, p1, p2, val;
    cin >> n >> m;
    vector<vector<int>> grid;
    for (int i = 0; i < m; i++) {
        cin >> p1 >> p2 >> val;
        grid.push_back({p1, p2, val});
    }
    int start = 1;//起点
    int end = n;  //终点

    vector<int> minDist(n + 1, INT_MAX);
    minDist[start] = 0;
    for (int i = 1; i < n; i++) {
        for (vector<int> &side: grid) {
            int from = side[0];
            int to = side[1];
            int price = side[2];
            //松弛操作
            //防止从为计算过的节点出发
            if (minDist[from] != INT_MAX && minDist[to] > minDist[from] + price) {
                minDist[to] = minDist[from] + price;
            }
        }
    }
    if (minDist[end] == INT_MAX) cout << "unconnected" << endl;
    else
        cout << minDist[end] << endl;
    return 0;
}