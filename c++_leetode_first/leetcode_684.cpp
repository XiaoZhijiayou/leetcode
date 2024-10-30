//
// Created by 11818 on 2024/10/27.
//
//leetcode684：冗余连接
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> father;
    void UnionFind(int num) {
        for (int i = 0; i < num; i++) {
            father.push_back(i);
        }
    }
    int Find(int n) {
        if (father[n] == n)
            return n;
        father[n] = Find(father[n]);//路径压缩版本
        return father[n];
    }
    bool Union(int a, int b) {
        //返回ab是不是在一个树里面
        int fa = Find(a);
        int fb = Find(b);
        bool res = fa == fb;
        father[fb] = fa;
        return res;
    }
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int n = edges.size();
        UnionFind(n + 1);//进行一下初始化部分
        vector<int> result(2, 0);
        for (auto e: edges) {
            int u = e[0];
            int v = e[1];
            if (Union(u, v)) {
                result[0] = u;
                result[1] = v;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};

    vector<int> res = s.findRedundantConnection(edges);
    for (auto i: res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}