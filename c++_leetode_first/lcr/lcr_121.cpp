//
// Created by 11818 on 2024/10/31.
//
// LCR121:  寻找目标值-二维数组
// 给定一个 m x n 的矩阵，每一行和每一列都按升序排列，请你从中找出两个数，使它们的和等于目标值 target。
//
// 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//方法一：就是对于每一行都进行一下遍历，搜索大于等于target的对应的迭代器
//算法复杂度:O（m*log2 n）
//class Solution {
//public:
//    bool findTargetIn2DPlants(vector<vector<int>>& plants, int target) {
//        //直接每行每行的搜索
//        for(auto row:plants){
//            auto it = lower_bound(row.begin(),row.end(),target) - row.begin();
//            if(it < row.size() && row[it] == target)
//                return true;
//        }
//        return false;
//    }
//};
//方法二：就是从右上角往左下角去遍历 O(m + n)
class Solution{
public:
    bool findTargetIn2DPlants(vector<vector<int>>& plants, int target) {
        if(plants.empty()){
            return false;
        }
        //起点位置
        int m = plants.size(), n = plants[0].size();
        int i = 0, j = n -1;
        while(i < m && j >= 0){
            if(plants[i][j] == target){
                return true;
            } else if(plants[i][j] > target){
                --j;
            }else{
                i++;
            }
        }
        return false;
    }
};
int main() {
    vector<vector<int>> plants = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int target = 7;
    Solution solution;
    bool res = solution.findTargetIn2DPlants(plants, target);
    cout << res << endl;
    return 0;
}