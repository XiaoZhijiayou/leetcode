//
// Created by 11818 on 2024/12/22.
//
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int next = target - nums[i];
            if (map.find(next) != map.end()) {
                return {map[next], i};
            } else {
                map.insert({nums[i], i});
            }
        }
        return {};
    }
};