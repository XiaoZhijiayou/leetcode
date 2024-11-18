//
// Created by 11818 on 2024/11/18.
//
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int result = 0;
    int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                for (int k = 0; k < 4; k++) {
                    int x = i + dir[k][0];
                    int y = j + dir[k][1];
                    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) result++;
                }
            }
        }
    }
    cout << result << endl;
    return 0;
}