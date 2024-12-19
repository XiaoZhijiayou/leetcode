//
// Created by 11818 on 2024/11/21.
//

/**
 * 59.螺旋矩阵 ||
 * 给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵
 * 例如： n = 3;
 *      1 2 3
 *      8 9 4
 *      7 6 5
 * */

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int startx = 0, starty = 0;/// 定义每次循环一圈的起始位置
        int loop = n / 2;          /// 每个圈循环几次，例如n为奇数3,那么loop = 1 只能循环一次
        int mid = n / 2;           /// 每个圈循环几次，例如n为奇数，中间的位置就是(1,1),n为5，中间的位置为(2,2)
        int count = 1;             /// 用来给矩阵中每一个空格赋值
        int offset = 1;            /// 需要控制每一条边遍历的长度，每次循环右边界收缩一位
        int i, j;
        while (loop--) {
            i = startx;
            j = starty;

            /// 下面开始四个for循环模拟转了一圈
            /// 模拟填充从左到右
            for (j; j < n - offset; j++) {
                res[i][j] = count++;
            }

            for (i; i < n - offset; i++) {
                res[i][j] = count++;
            }

            for (j; j > starty; j--) {
                res[i][j] = count++;
            }

            for (i; i > startx; i--) {
                res[i][j] = count++;
            }

            startx++;
            starty++;

            offset += 1;/// 需要将右边的边界空白前移一位
        }
        if (n % 2) {
            res[mid][mid] = count;
        }
        return res;
    }
};

int main() {
    Solution s;
    int n = 3;
    auto res = s.generateMatrix(n);
    for (auto v: res) {
        for (auto i: v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}