//
// Created by 11818 on 2024/11/14.
//
//101.岛屿的总面积
//给定一个由 1（陆地）和 0（水）组成的矩阵，岛屿指的是由水平或垂直方向上相邻的陆地单元格组成的区域，
// 且完全被水域单元格包围。孤岛是那些位于矩阵内部、所有单元格都不接触边缘的岛屿

//解决题目的思路部分
//先将沿着周边的所有岛屿全部遍历完全，将其临边的岛屿都改为海洋
//然后再去遍历全部的岛屿，这样就只剩下孤岛部分了
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};// 保存四个方向
int count_res;                             // 统计符合题目要求的陆地空格数量

void bfs(vector<vector<int>> &grid, int x, int y) {
    queue<pair<int, int>> que;
    que.push({x, y});
    grid[x][y] = 0;
    count_res++;
    while (!que.empty()) {
        auto cur = que.front();
        int cur_x = cur.first;
        int cur_y = cur.second;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int next_x = cur_x + dir[i][0];
            int next_y = cur_y + dir[i][1];
            if (next_x < 0 || next_x >= grid.size() || next_y < 0 || next_y >= grid[0].size()) continue;
            if (grid[next_x][next_y] == 1) {
                que.push({next_x, next_y});
                count_res++;
                grid[next_x][next_y] = 0;
            }
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

    //开始后续的遍历部分
    //先将周边的先遍历完全
    for (int i = 0; i < n; i++) {
        if (grid[i][0] == 1) bfs(grid, i, 0);
        if (grid[i][m - 1] == 1) bfs(grid, i, m - 1);
    }

    for (int i = 0; i < m; i++) {
        if (grid[0][i] == 1) bfs(grid, 0, i);
        if (grid[n - 1][i] == 1) bfs(grid, n - 1, i);
    }

    count_res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) bfs(grid, i, j);
        }
    }
    cout << count_res << endl;
}