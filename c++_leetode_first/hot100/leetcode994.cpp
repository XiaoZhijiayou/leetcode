//
// Created by 11818 on 2024/11/8.
//
//这个里面是利用了队列的形式来进行处理，这个是保证了一层层的往外面扩充的形式，每扩充一层就直接对应的++操作
//1.先寻找到腐烂的橘子。插入到队列之中
//2.通过腐烂的橘子部分，然后对应的就是开始对应这个队列部分记下他的大小部分
//3.然后开始遍历每个值，对于每个值部分都在其周围寻找新鲜的橘子，然后把新鲜的橘子变成2，然后插入到队列中去
//注意这一层的遍历中是不考虑这个新插入的部分的，所以只是把之前的size遍历完全就可以了
//然后最后遍历完全查看有没有没有遍历到的新鲜橘子
//有没遍历到的就直接返回-1，没有的话就直接返回result部分！！！
#include <iostream>
#include <queue>
#include <vector>
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        queue<PII> q;
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (g[i][j] == 2)
                    q.push({i, j});

        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

        int res = 0;
        if (q.size()) res -- ;
        while (q.size()) {
            res ++ ;
            int sz = q.size();
            while (sz -- ) {
                auto t = q.front();
                q.pop();
                for (int i = 0; i < 4; i ++ ) {
                    int x = t.x + dx[i], y = t.y + dy[i];
                    if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] != 1)
                        continue;
                    g[x][y] = 2;
                    q.push({x, y});
                }
            }
        }

        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (g[i][j] == 1)
                    return -1;
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout<<s.orangesRotting(grid)<<endl;
    return 0;
}