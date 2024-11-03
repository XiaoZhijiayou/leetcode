//
// Created by 11818 on 2024/11/3.
//
//LCR129:字母迷宫
//这个就是一个简单的动态规划
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    bool exit(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &visited, string target, int k) {
        if (grid[i][j] != target[k]) {
            return false;
        } else if (k == target.size() - 1) {
            return true;
        }
        visited[i][j] = true;
        bool result = false;
        for (int dir = 0; dir < 4; dir++) {
            int x = i + dx[dir];
            int y = j + dy[dir];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
                if (!visited[x][y]) {
                    bool flag = exit(grid, x, y, visited, target, k + 1);
                    if (flag) {
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;
        return result;
    }
    bool wordPuzzle(vector<vector<char>> &grid, string target) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < visited.size(); i++) {
            for (int j = 0; j < visited[0].size(); j++) {
                bool flag = exit(grid, i, j, visited, target, 0);
                if (flag) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution S;
    vector<vector<char>> grid = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string target = "ABCCED";
    cout << S.wordPuzzle(grid, target) << endl;
    return 0;
}
