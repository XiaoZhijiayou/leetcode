//
// Created by 11818 on 2024/11/14.
//

//103.水流问题
//现有一个 N × M 的矩阵，每个单元格包含一个数值，这个数值代表该位置的相对高度。
//矩阵的左边界和上边界被认为是第一组边界，而矩阵的右边界和下边界被视为第二组边界。

//矩阵模拟了一个地形，当雨水落在上面时，水会根据地形的倾斜向低处流动，但只能从较高或等高的地点流向较低或等高并且相邻（上下左右方向）的地点。
// 我们的目标是确定那些单元格，从这些单元格出发的水可以达到第一组边界和第二组边界。

//输入描述：
//第一行包含两个整数 N 和 M，分别表示矩阵的行数和列数。
//后续 N 行，每行包含 M 个整数，表示矩阵中的每个单元格的高度。

//输出描述：
//输出共有多行，每行输出两个整数，用一个空格隔开，
//表示可达第一组边界和第二组边界的单元格的坐标，输出顺序任意。

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};

//从x，y出发，把可以走的地方都标记上
void dfs(const vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y) {
    if (visited[x][y]) return;
    queue<pair<int, int>> que;
    que.push({x, y});
    visited[x][y] = true;
    while (!que.empty()) {
        auto cur = que.front();
        que.pop();
        int cur_x = cur.first;
        int cur_y = cur.second;
        for (int i = 0; i < 4; i++) {
            int next_x = cur_x + dir[i][0];
            int next_y = cur_y + dir[i][1];
            if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) continue;
            if (grid[next_x][next_y] > grid[x][y]) continue;
            dfs(grid, visited, next_x, next_y);
        }
    }
    return;
}

//判断这个点开始，是否可以满足到达第一和第二边界
bool is_result(vector<vector<int>> &grid, int x, int y) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    dfs(grid, visited, x, y);
    bool is_First = false;
    bool is_Second = false;
    //进行判断第一边界和第二边界
    for (int i = 0; i < m; i++) {
        if (visited[0][m - 1]) {
            is_First = true;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (visited[n - 1][0]) {
            is_First = true;
            break;
        }
    }
    for (int i = 0; i < m; i++) {
        if (visited[n - 1][i]) {
            is_Second = true;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (visited[i][m - 1]) {
            is_Second = true;
            break;
        }
    }

    if (is_First && is_Second) return true;
    return false;
}


int main() {
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (is_result(grid, i, j)) {
                cout << i << " " << j << endl;
            }
        }
    }
    return 0;
}


//第二种方式的优化方案：从两个边界出发进行扩展填充
//#include <iostream>
//#include <vector>
//using namespace std;
//int n, m;
//int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};
//void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
//    if (visited[x][y]) return;
//
//    visited[x][y] = true;
//
//    for (int i = 0; i < 4; i++) {
//        int nextx = x + dir[i][0];
//        int nexty = y + dir[i][1];
//        if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m) continue;
//        if (grid[x][y] > grid[nextx][nexty]) continue; // 注意：这里是从低向高遍历
//
//        dfs (grid, visited, nextx, nexty);
//    }
//    return;
//}
//
//
//
//int main() {
//
//    cin >> n >> m;
//    vector<vector<int>> grid(n, vector<int>(m, 0));
//
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cin >> grid[i][j];
//        }
//    }
//    // 标记从第一组边界上的节点出发，可以遍历的节点
//    vector<vector<bool>> firstBorder(n, vector<bool>(m, false));
//
//    // 标记从第一组边界上的节点出发，可以遍历的节点
//    vector<vector<bool>> secondBorder(n, vector<bool>(m, false));
//
//    // 从最上和最下行的节点出发，向高处遍历
//    for (int i = 0; i < n; i++) {
//        dfs (grid, firstBorder, i, 0); // 遍历最左列，接触第一组边界
//        dfs (grid, secondBorder, i, m - 1); // 遍历最右列，接触第二组边界
//    }
//
//    // 从最左和最右列的节点出发，向高处遍历
//    for (int j = 0; j < m; j++) {
//        dfs (grid, firstBorder, 0, j); // 遍历最上行，接触第一组边界
//        dfs (grid, secondBorder, n - 1, j); // 遍历最下行，接触第二组边界
//    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            // 如果这个节点，从第一组边界和第二组边界出发都遍历过，就是结果
//            if (firstBorder[i][j] && secondBorder[i][j]) cout << i << " " << j << endl;;
//        }
//    }
//
//
//}