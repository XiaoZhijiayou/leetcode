//
// Created by 11818 on 2024/11/19.
//
//117.软件构建
/**拓扑排序
 * 就两步骤：
 * 1.找到入度为0的节点，加入结果集合
 * 2.将该节点从图中移除
 * */
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
    int n, m, s, t;
    cin >> n >> m;
    vector<int> inDegree(n, 0);//记录每个文件的入度
    vector<int> result;        //记录结果
    unordered_map<int, vector<int>> umap;
    while (m--) {
        cin >> s >> t;
        inDegree[t]++;       //t的入度++
        umap[s].push_back(t);//记录s指向哪些文件
    }
    queue<int> que;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) que.push(i);
    }

    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        result.push_back(cur);
        vector<int> files = umap[cur];
        if (files.size()) {
            for (int i = 0; i < files.size(); i++) {
                inDegree[files[i]]--;
                if (inDegree[files[i]] == 0) que.push(files[i]);
            }
        }
    }
    if (result.size() == n) {
        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}