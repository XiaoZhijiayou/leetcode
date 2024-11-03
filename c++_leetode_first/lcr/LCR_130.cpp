//
// Created by 11818 on 2024/11/3.
//
//LCR130:衣橱整理
#include <iostream>
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int wardrobeFinishing(int m, int n, int cnt) {
        vector<vector<bool>> visited(m,vector<bool>(n, false));
        //保存什么位置遍历过
        auto f = [](int x){
            return x /10 + x % 10;
        };
        function<int(int, int)> dfs = [&](int i , int j) -> int {
            if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || f(i) + f(j) > cnt){
                return 0;
            }
            visited[i][j] = true;
            return  1 + dfs(i + 1,j) + dfs(i,j + 1);
        };
        return dfs(0,0);
    }
};

int main(){
    int m = 4, n = 7, cnt = 5;
    Solution s;
    cout<<s.wardrobeFinishing(m,n,cnt);
    return 0;
}