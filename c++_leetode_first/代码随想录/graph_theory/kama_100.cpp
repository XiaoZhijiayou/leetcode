//
// Created by 11818 on 2024/11/14.
//
#include <iostream>
#include <queue>
#include <vector>
int count_res;
using namespace std;
//一下是bfs广度优先遍历

//int dx[] = {-1, 0, 1, 0};
//int dy[] = {0, 1, 0, -1};
//void bfs(vector<vector<bool>> &visited, const vector<vector<int>> &grid, int x, int y) {
//    queue<pair<int, int>> que;
//    que.push({x, y});
//    visited[x][y] = true;
//    while (!que.empty()) {
//        auto cur = que.front();
//        que.pop();
//        int curx = cur.first;
//        int cury = cur.second;
//        for (int i = 0; i < 4; i++) {
//            int next_x = curx + dx[i];
//            int next_y = cury + dy[i];
//            if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size()) continue;
//            if (!visited[next_x][next_y] && grid[next_x][next_y] == 1) {
//                count_res++;
//                que.push({next_x, next_y});
//                visited[next_x][next_y] = true;
//            }
//        }
//    }
//}
//int main() {
//    int n, m;
//    cin >> n >> m;
//    vector<vector<int>> grid(n, vector<int>(m, 0));
//
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cin >> grid[i][j];
//        }
//    }
//
//    //得到了grid的参数部分
//
//    vector<vector<bool>> visited(n, vector<bool>(m, false));
//    int result = 0;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            if (!visited[i][j] && grid[i][j] == 1) {
//                count_res = 1;
//                visited[i][j] = true;
//                bfs(visited, grid, i, j);
//                result = max(result, count_res);
//            }
//        }
//    }
//    cout << result << endl;
//}


//以下是DFS深度优先遍历
// 版本一
int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};// 四个方向
void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        if (nextx < 0 || nextx >= grid.size() || nexty < 0 || nexty >= grid[0].size()) continue;// 越界了，直接跳过
        if (!visited[nextx][nexty] && grid[nextx][nexty] == 1) {                                // 没有访问过的 同时 是陆地的
            visited[nextx][nexty] = true;
            count_res++;
            dfs(grid, visited, nextx, nexty);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                count_res = 1;// 因为dfs处理下一个节点，所以这里遇到陆地了就先计数，dfs处理接下来的相邻陆地
                visited[i][j] = true;
                dfs(grid, visited, i, j);// 将与其链接的陆地都标记上 true
                result = max(result, count_res);
            }
        }
    }
    cout << result << endl;
}