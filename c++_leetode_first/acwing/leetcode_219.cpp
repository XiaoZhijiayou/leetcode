//
// Created by 11818 on 2024/10/29.
//
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
//利用hash表来进行存储，一下对应的数字下标，通过已经遍历的数存储在hash表中，
//这样就寻找当前的有没有再hash表中出现

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if (hash.count(x) && abs(i - hash[x]) <= k) return true;
            hash[x] = i;
        }
        return false;
    }
};
int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;
    cout << s.containsNearbyDuplicate(nums, k) << endl;
    return 0;
}