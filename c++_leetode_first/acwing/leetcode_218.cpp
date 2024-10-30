//
// Created by 11818 on 2024/10/27.
//
//线性扫描法
#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
        vector<vector<int>> res;
        multiset<pair<int, int>> events;
        multiset<int> height;//这个是按照从小到大的排列顺序去排列的
        height.insert(0);    //为何要先插入一个0？？
        int n = buildings.size();
        for (int i = 0; i < n; i++) {
            events.insert(make_pair(buildings[i][0], -buildings[i][2]));
            events.insert(make_pair(buildings[i][1], buildings[i][2]));
        }//左端点的高度是负数，右端点的高度是正数
        for (auto p: events) {
            if (p.second < 0) {
                //对应上是左端点的话
                if (-p.second > *height.rbegin())
                    res.push_back({p.first, -p.second});//保留下最大的那个
                height.insert(-p.second);
            } else {
                //如果为右端点
                //就是把前面那个端点的高度舍去了
                height.erase(height.find(p.second));
                if (p.second > *height.rbegin())
                    res.push_back({p.first, *height.rbegin()});
            }
        }
        return res;
    }
};
int main() {
    Solution s;
    vector<vector<int>> buildings = {{0, 2, 3}, {2, 5, 3}};
    vector<vector<int>> res = s.getSkyline(buildings);
    for (auto a: res) {
        cout << "x坐标：  " << a[0] << "y坐标：   " << a[1] << endl;
    }
    return 0;
}
