//
// Created by 11818 on 2024/10/26.
//
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> grapth(numCourses);
        vector<int> depth(numCourses,0);
        //开始创建拓扑表
        for(auto i : prerequisites){
            grapth[i[1]].push_back(i[0]);
            depth[i[0]]++;
        }
        //然后开始找出来没有度的课程节点，将他加入遍历的队列中去。
        queue<int> que;
        for(int i = 0; i < depth.size();i++){
            if(depth[i] == 0)
                que.push(i);
        }
        //然后开始遍历队列
        vector<int> result;
        while(que.size()){
            auto t = que.front();
            que.pop();
            result.push_back(t);
            for(auto i : grapth[t]){
                depth[i]--;
                if(depth[i] == 0)
                    que.push(i);
                //这个部分相当于如果前序课程都学完了，才可以下来的课程
            }
        }
        if(result.size() < numCourses)
            return {};
        return result;
    }
};
int main() {
    Solution s;
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    auto result = s.findOrder(numCourses,prerequisites);
    for(auto i : result){
        cout << i << " ";
    }
    return 0;
}