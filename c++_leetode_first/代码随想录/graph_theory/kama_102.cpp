//
// Created by 11818 on 2024/11/14.
//

//102.沉没孤岛

//给定一个由 1（陆地）和 0（水）组成的矩阵，岛屿指的是由水平或垂直方向上相邻的陆地单元格组成的区域，
// 且完全被水域单元格包围。孤岛是那些位于矩阵内部、所有单元格都不接触边缘的岛屿。
//现在你需要将所有孤岛“沉没”，即将孤岛中的所有陆地单元格（1）转变为水域单元格（0）。

//解题思路
//1.深搜或者广搜将地图周边的 1 （陆地）全部改成 2 （特殊标记）
//2.将水域中间 1 （陆地）全部改成 水域（0）
//3.将之前标记的 2 改为 1 （陆地）


#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

void bfs(vector<vector<int>> &grid, int x, int y) {
    queue<pair<int, int>> que;
    que.push({x, y});
    grid[x][y] = 2;
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
                grid[next_x][next_y] = 2;
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

    //对边界部分开始处理步骤一
    for (int i = 0; i < n; i++) {
        if (grid[i][0] == 1) bfs(grid, i, 0);
        if (grid[i][m - 1] == 1) bfs(grid, i, m - 1);
    }

    for (int i = 0; i < m; i++) {
        if (grid[0][i] == 1) bfs(grid, 0, i);
        if (grid[n - 1][i] == 1) bfs(grid, n - 1, i);
    }

    //然后开始变为二的部分把其变为0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) grid[i][j] = 0;
            if (grid[i][j] == 2) grid[i][j] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}