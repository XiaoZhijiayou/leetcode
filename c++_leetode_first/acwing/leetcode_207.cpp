//
// Created by 11818 on 2024/10/26.
//
//有向图的拓扑排序，判断是否可以完成所有课程的学习。
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);//图的邻接表
        vector<int> indegree(numCourses, 0);//这个是每个节点的入度

        //建立图的邻接表
        // 1. 遍历prerequisites，将prerequisites[i][1]作为边的终点，prerequisites[i][0]作为边的起点，建立边
        // 2. 对于每个prerequisites[i][0]，将其入度+1
        for (auto p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;//因为想要学习课程p[0]，必须先学习课程p[1]，所以对应的p[0]的入度+1
        }
        queue<int> q;
        vector<bool> visited(numCourses, false);//标记是否访问过
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){//如果入度为0，说明这个节点没有前置节点，可以作为起点
                q.push(i);
            }
        }
        //拓扑排序:j从0开始，每次从队列中取出一个节点，将其所有出边的入度-1，如果入度变为0，则将其放入队列中
        while(!q.empty()) {
            int sta = q.front();
            q.pop();
            visited[sta] = true;
            for (int i = 0; i < graph[sta].size(); i++) {
                indegree[graph[sta][i]]--;
                if (indegree[graph[sta][i]] == 0) {
                    q.push(graph[sta][i]);
                }
            }
        }
        //判断是否可以完成所有课程的学习
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){//如果没有访问过，说明这个课程还没有学习，不能完成所有课程的学习
                return false;
            }
        }
        //如果可以完成所有课程的学习，返回true
        return true;
    }
};

int main() {
    Solution s;
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0},{0,1}};
    cout << s.canFinish(numCourses, prerequisites) << endl;
    return 0;
}