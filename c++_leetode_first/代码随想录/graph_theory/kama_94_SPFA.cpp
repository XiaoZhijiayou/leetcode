//
// Created by 11818 on 2024/11/20.
//
//Bellman_ford队列优化算法(SPFA)
#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;
struct Edge {
    int to;
    int val;
    Edge(int t, int w) : to(t), val(w) {}//构造函数
};
int main() {
    int n, m, p1, p2, val;
    cin >> n >> m;
    vector<list<Edge>> grid(n + 1);
    vector<bool> isInQueue(n + 1);//加入优化，已经在队列里面的元素就不需要重复添加了
    //将所有边保存起来
    for (int i = 0; i < m; i++) {
        cin >> p1 >> p2 >> val;
        grid[p1].push_back(Edge(p2, val));
    }
    int start = 1;
    int end = n;
    vector<int> minDist(n + 1, INT_MAX);
    minDist[start] = 0;

    queue<int> que;
    que.push(start);

    while (!que.empty()) {
        int node = que.front();
        que.pop();
        isInQueue[node] = false;
        for (auto edge: grid[node]) {
            int from = node;
            int to = edge.to;
            int value = edge.val;
            if (minDist[to] > minDist[from] + value) {
                minDist[to] = minDist[from] + value;
                if (isInQueue[to] == false) {
                    que.push(to);
                    isInQueue[to] = true;
                }
            }
        }
    }
    if (minDist[end] == INT_MAX) cout << "unconnected" << endl;
    else
        cout << minDist[n] << endl;
    return 0;
}