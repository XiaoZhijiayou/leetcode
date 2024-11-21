//
// Created by 11818 on 2024/11/19.
//
#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;
//小顶堆
class myComparsion {
public:
    bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) {
        return lhs.second > rhs.second;
    }
};
//定义一个结构表示带权重的边
struct Edge {
    int to; //邻接顶点
    int val;//边的权重
    Edge(int t, int w) : to(t), val(w) {}
};
int main() {
    int n, m, p1, p2, val;
    cin >> n >> m;
    vector<list<Edge>> grid(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> p1 >> p2 >> val;
        grid[p1].push_back(Edge(p2, val));
    }
    int start = 1;
    int end = n;
    //存储从原点到每个点的最短距离
    vector<int> minDist(n + 1, INT_MAX);
    //记录哪些顶点是否被访问过
    vector<bool> visited(n + 1, false);
    //优先队列中存放pair<节点，原点到节点的权值>
    priority_queue<pair<int, int>, vector<pair<int, int>>, myComparsion> pq;
    //初始化队列
    pq.push(pair<int, int>(start, 0));
    minDist[start] = 0;
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (visited[cur.first]) continue;
        visited[cur.first] = true;
        for (auto edge: grid[cur.first]) {
            if (!visited[edge.to] && minDist[cur.first] + edge.val < minDist[edge.to]) {
                minDist[edge.to] = minDist[cur.first] + edge.val;
                pq.push(pair<int, int>(edge.to, minDist[edge.to]));
            }
        }
    }
    if (minDist[end] == INT_MAX) cout << -1 << endl;
    else
        cout << minDist[end] << endl;
    return 0;
}