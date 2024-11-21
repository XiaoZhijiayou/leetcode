//
// Created by 11818 on 2024/11/21.
//

//Astar 是一种 广搜的改良版
//关键在于启发式函数
//启发式函数要影响的就是队列中元素的排序

#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int moves[1001][1001];
int dir[8][2] = {-1, -2, -2, -1, -2, 1, -1, 2, 1, 2, 2, 1, 2, -1, 1, -2};
int b1, b2;//这个是终点
//F = G + H;
//G就是从起点到该节点的路径消耗
//H就是该节点到终点的路径消耗

struct Knight {
    int x, y;
    int g, h, f;
    bool operator<(const Knight &k) const {
        return k.f < f;
    }
};

priority_queue<Knight> que;

int Heuristic(const Knight &k) {
    return (k.x - b1) * (k.x - b1) + (k.y - b2) * (k.y - b2);//统一不开根号这样可以提高精度
}

void astar(const Knight &k) {
    Knight cur, next;
    que.push(k);
    while (!que.empty()) {
        cur = que.top();
        que.pop();
        if (cur.x == b1 && cur.y == b2) break;
        for (int i = 0; i < 8; i++) {
            next.x = cur.x + dir[i][0];
            next.y = cur.y + dir[i][1];
            if (next.x < 1 || next.x > 1000 || next.y < 1 || next.y > 1000) continue;
            if (!moves[next.x][next.y]) {
                moves[next.x][next.y] = moves[cur.x][cur.y] + 1;
                //开始计算F
                next.g = cur.g + 5;//统一不开根号可以提高精度其实就是每次路径的平方和相加
                next.h = Heuristic(next);
                next.f = next.g + next.h;
                que.push(next);
            }
        }
    }
}

int main() {
    int n, a1, a2;
    cin >> n;
    while (n--) {
        cin >> a1 >> a2 >> b1 >> b2;
        memset(moves, 0, sizeof(moves));
        Knight start;
        start.x = a1;
        start.y = a2;
        start.g = 0;
        start.h = Heuristic(start);
        start.f = start.g + start.h;
        astar(start);
        while (!que.empty()) que.pop();
        cout << moves[b1][b2] << endl;
    }
    return 0;
}