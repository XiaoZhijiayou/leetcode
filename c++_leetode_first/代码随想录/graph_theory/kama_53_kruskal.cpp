//
// Created by 11818 on 2024/11/19.
//

/**
 * kruscal的思路:
 * 1.边的权值排序，因为要优先选最小的边加入到生成树里
 * 2.遍历排序后的边
 *  1.如果边首尾的两个节点在同一个集合，说明如果连上这条边图中会出现环
 *  2.如果边首尾的两个节点不在同一个集合，加入到最小生成树，并把两个节点加入同一个集合
 * */

/**这里面的在不在一个集合里面是这样判断的
 * ：创建一个并查集就可以了
 * */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//l,r为两边的节点，val为边的数值
struct Edge {
    int l, r, val;
};

//节点的数量
int n = 10001;
vector<int> father(n, -1);

//并查集的初始化部分
void init() {
    for (int i = 0; i < n; i++) {
        father[i] = i;
    }
}

int find(int u) {
    return u == father[u] ? u : u = find(father[u]);
}

//并查集的加入集合
void join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    father[v] = u;
}

int main() {
    int v, e;
    cin >> v >> e;
    int v1, v2, val;
    int result = 0;
    vector<Edge> edges;
    while (e--) {
        cin >> v1 >> v2 >> val;
        edges.push_back({v1, v2, val});
    }

    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.val < b.val;
    });

    //并查集初始化
    init();
    //从头开始遍历
    for (auto edge: edges) {
        int x = find(edge.l);
        int y = find(edge.r);
        if (x != y) {
            result += edge.val;
            join(edge.l, edge.r);
        }
    }
    cout << result << endl;
    return 0;
}