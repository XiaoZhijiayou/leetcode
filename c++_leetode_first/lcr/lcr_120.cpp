//
// Created by 11818 on 2024/10/30.
//
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
//class Solution {
//public:
//    int findRepeatNumber(vector<int>& nums) {
//        unordered_set<int> vis;
//        for (int i = 0;; ++i) {
////            if (vis.count(nums[i])) {
//            if(vis.find(nums[i]) != vis.end()){
//                return nums[i];
//            }
//            vis.insert(nums[i]);
//        }
//    }
//};

class Solution {
public:
    int findRepeatDocument(vector<int> &documents) {
        unordered_map<int, int> hash;
        for (auto i: documents) {
            if (hash.find(i) != hash.end())
                return i;
            hash[i]++;
        }
        return 0;
    }
};
int main() {
    Solution S;
    vector<int> nums = {2, 5, 3, 0, 5, 0};
    cout << S.findRepeatDocument(nums) << endl;
}