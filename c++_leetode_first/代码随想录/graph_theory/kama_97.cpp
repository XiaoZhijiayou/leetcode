//
// Created by 11818 on 2024/11/21.
//
//kama_97.小明逛公园
//Floyd算法
//动态规划五部曲：
//1.确定dp数组以及下标的含义
//2.确定递归公式
//3.dp数组如何初始化
//4.确定遍历顺序
//5.举例推到dp数组

/**
 * 1.dp数组以及下标的含义
 * grid[i][j][k] = m;表示节点i到节点j以【1-k】集合为中间节点的最短距离为m；
 * 2.递归公式：分为两种情况：1.节点i到节点j的最短路径经过k 2.节点i到节点j的最短路径不经过k
 *          1.grid[i][j][k] = grid[i][k][k - 1] + grid[k][j][k - 1]
 *          节点i 到 节点k 的最短距离 是不经过节点k，中间节点集合为[1...k-1]，所以 表示为grid[i][k][k - 1]
 *          节点k 到 节点j 的最短距离 也是不经过节点k，中间节点集合为[1...k-1]，所以表示为 grid[k][j][k - 1]
 *          2.grid[i][j][k] = grid[i][j][k - 1]
 *          如果节点i 到 节点j的最短距离 不经过节点k，那么 中间节点集合[1...k-1]，表示为 grid[i][j][k - 1]
 *grid[i][j][k] = min(grid[i][k][k - 1] + grid[k][j][k - 1]， grid[i][j][k - 1])
 *
 * 3.dp数组的初始化部分：grid[i][j][k] = m，表示 节点i 到 节点j 以[1...k] 集合为中间节点的最短距离为m。
 * 刚开始初始化k 是不确定的。
 *例如题目中只是输入边（节点2 -> 节点6，权值为3），那么grid[2][6][k] = 3，k需要填什么呢？
 * 把k 填成1，那如何上来就知道 节点2 经过节点1 到达节点6的最短距离是多少 呢。
 * 所以 只能 把k 赋值为 0，本题 节点0 是无意义的，节点是从1 到 n。
 * 这样我们在下一轮计算的时候，就可以根据 grid[i][j][0] 来计算 grid[i][j][1]，
 * 此时的 grid[i][j][1] 就是 节点i 经过节点1 到达 节点j 的最小距离了。
 * 4.遍历顺序：从递推公式：grid[i][j][k] = min(grid[i][k][k - 1] + grid[k][j][k - 1]， grid[i][j][k - 1])
 * 可以看出，我们需要三个for循环，分别遍历i，j 和k
 * 遍历k 的for循环一定是在最外面
 * 至于遍历 i 和 j 的话，for 循环的先后顺序无所谓
 * */

#include <iostream>
#include <list>
#include <vector>
using namespace std;
int main() {
    int n, m, p1, p2, val;
    cin >> n >> m;
    vector<vector<vector<int>>> grid(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 10005)));//因为边的最大距离是10^5
    for (int i = 0; i < m; i++) {
        cin >> p1 >> p2 >> val;
        grid[p1][p2][0] = val;
        grid[p2][p1][0] = val;
    }
    //开始floyd
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                grid[i][j][k] = min(grid[i][j][k - 1], grid[i][k][k - 1] + grid[k][j][k - 1]);
            }
        }
    }
    int z, start, end;
    cin >> z;
    while (z--) {
        cin >> start >> end;
        if (grid[start][end][n] == 10005) cout << -1 << endl;
        else
            cout << grid[start][end][n] << endl;
    }
    return 0;
}