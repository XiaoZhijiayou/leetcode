#include <vector>
#include <iostream>
#include <cstdint>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int x = 0, y = 0;
        int mid = n / 2;
        int num = 1;
        int loop = n / 2; // 循环次数
        int offset = 1; //每次循环边的偏移量
        vector<vector<int>> res(n, vector<int>(n, 0));
        while (loop--) {
            for (; x < n - offset; x++) {
                res[y][x] = num++;
            }
            for (; y < n - offset; y++) {
                res[y][x] = num++;
            }
            for (; x > offset - 1; x--) {
                res[y][x] = num++;
            }
            for (; y > offset - 1; y--) {
                res[y][x] = num++;
            }
            offset++;
            x++;
            y++;
        }
        if (n % 2) {
            res[mid][mid] = num;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> res = s.generateMatrix(4);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}