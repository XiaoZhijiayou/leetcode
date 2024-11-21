//
// Created by 11818 on 2024/11/18.
//
#include <iostream>
#include <vector>
using namespace std;
int n;//节点数量
vector<int> father(1001, 0);
//并查集初始化
void init() {
    for (int i = 0; i < n; i++) {
        father[i] = i;
    }
}
//并查集里寻根操作
int find(int u) {
    return u == father[u] ? u : father[u] = find(father[u]);
}
//判断uv是否是同一个根
bool isSame(int u, int v) {
    u = find(u);
    v = find(v);
    return u == v;
}
//将v->u这条边加入并查集
void join(int u, int v) {
    u = find(u);       //寻找u的根
    v = find(v);       //寻找v的根
    if (u == v) return;//如果发现相同则说明在一个集合中，不用两个节点链接直接返回
    father[v] = u;
}
int main() {
    int s, t;
    cin >> n;
    init();
    for (int i = 1; i <= n; i++) {
        cin >> s >> t;
        if (isSame(s, t)) {
            cout << s << " " << t << endl;
            return 0;
        } else {
            join(s, t);
        }
    }
    return 0;
}
//就判断一下边的两个节点在不在同一个集合就可以了
