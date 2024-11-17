//
// Created by 11818 on 2024/11/17.
//
//104.建造最大的岛屿
//题目描述
//给定一个由 1（陆地）和 0（水）组成的矩阵，你最多可以将矩阵中的一格水变为一块陆地，在执行了此操作之后，矩阵中最大的岛屿面积是多少。
//岛屿面积的计算方式为组成岛屿的陆地的总数。岛屿是被水包围，并且通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设矩阵外均被水包围。
//输入描述
//第一行包含两个整数 N, M，表示矩阵的行数和列数。之后 N 行，每行包含 M 个数字，数字为 1 或者 0，表示岛屿的单元格。
//输出描述
//输出一个整数，表示最大的岛屿面积。

#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
int n, m;
int count_;
int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visit, int x, int y, int mark) {
    if (visit[x][y] || grid[x][y] == 0) return;
    queue<pair<int, int>> que;
    que.push({x, y});
    visit[x][y] = true;
    grid[x][y] = mark;
    count_++;
    while (!que.empty()) {
        auto cur = que.front();
        que.pop();
        int cur_x = cur.first;
        int cur_y = cur.second;
        for (int i = 0; i < 4; i++) {
            int next_x = cur_x + dir[i][0];
            int next_y = cur_y + dir[i][1];
            if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) continue;
            dfs(grid, visit, next_x, next_y, mark);
        }
    }
}


int main() {
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visit(n, vector<bool>(m, false));
    unordered_map<int, int> gridNum;//用于存储key：编号 value：面积

    int mark = 2;         //记录每个岛屿的编号
    bool isAllGrid = true;//标记整个地图都是陆地
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) isAllGrid = false;
            if (!visit[i][j] && grid[i][j] == 1) {
                count_ = 0;
                dfs(grid, visit, i, j, mark);
                gridNum[mark] = count_;
                mark++;
            }
        }
    }
    if (isAllGrid) {
        cout << n * m << endl;
        return 0;
    }

    //一下是添加陆地的位置，并且计算周边岛屿之和
    int result = 0;
    unordered_set<int> visit_mark;//访问过的标记部分
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            count_ = 1;
            visit_mark.clear();
            if (grid[i][j] == 0) {
                for (int k = 0; k < 4; k++) {
                    int next_i = i + dir[k][0];
                    int next_j = j + dir[k][1];
                    if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= m) continue;
                    if (visit_mark.count(grid[next_i][next_j])) continue;//通过将相邻岛屿夹在一起
                    //把周围四面的岛屿数量都加在一起
                    count_ += gridNum[grid[next_i][next_j]];
                    visit_mark.insert(grid[next_i][next_j]);
                }
            }
            result = max(result, count_);
        }
    }
    cout << result << endl;
    return 0;
}
//该算法分为两步
//1.先将每个隔开的岛屿面积进行计算出来
//2.然后对于没有岛屿部分开始遍历啊，每个没有岛屿部分都算一下周围的岛屿相加之后，然后最后取出最大值就好