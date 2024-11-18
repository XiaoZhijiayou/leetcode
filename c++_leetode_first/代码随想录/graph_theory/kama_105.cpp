//
// Created by 11818 on 2024/11/18.
//
//105.有向图的完全可达性
#include <iostream>
#include <list>
#include <vector>
using namespace std;

void dfs(const vector<list<int>> &graph, int key_, vector<bool> &visited) {
    if (visited[key_]) {
        return;
    }
    visited[key_] = true;
    list<int> keys = graph[key_];
    for (auto key: keys) {
        dfs(graph, key, visited);
    }
}


int main() {
    int n, m, s, t;
    cin >> n >> m;
    //节点编号从1到n，所以申请n + 1这么大的数组
    vector<list<int>> graph(n + 1);
    while (m--) {
        cin >> s >> t;
        //使用邻接表，表示s->t是相连的
        graph[s].push_back(t);
    }
    vector<bool> visited(n + 1, false);
    dfs(graph, 1, visited);
    for (int i = 1; i <= n; i++) {
        if (visited[i] == false) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
}