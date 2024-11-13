//
// Created by 11818 on 2024/11/13.
//
//289.生命游戏
//1.如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
//2.如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
//3.如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
//4.如果死细胞周围正好有三个活细胞，则该位置死细胞复活；

//因为不让开辟新数组，所以就将后续的答案存在倒数第二位就可以了 例如 00 10 11 01
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void gameOfLife(vector<vector<int>> &board) {
        if (board.empty() || board[0].empty()) return;
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int live = 0;
                for (int x = max(0, i - 1); x <= min(n - 1, i + 1); x++)
                    for (int y = max(0, j - 1); y <= min(m - 1, j + 1); y++)
                        if ((board[x][y] & 1) && (x != i || y != j))
                            live++;
                int cur = board[i][j] & 1, next;
                if (cur) {
                    if (live < 2) next = 0;
                    else if (live == 2 || live == 3)
                        next = 1;
                    else {
                        next = 0;
                    }
                } else {
                    if (live == 3) next = 1;
                    else
                        next = 0;
                }
                board[i][j] |= next << 1;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] >>= 1;
            }
        }
        return;
    }
};

int main() {
    vector<vector<int>> board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    Solution s;
    s.gameOfLife(board);
    for (auto c: board) {
        for (auto i: c) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}