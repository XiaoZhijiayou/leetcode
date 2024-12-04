//
// Created by 11818 on 2024/12/1.
//

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        unordered_multiset<int> s;
        for (auto n: nums1) s.insert(n);
        vector<int> res;
        for (auto x: nums2) {
            if (s.count(x)) {
                res.push_back(x);
                s.erase(s.find(x));
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 2, 2, 1}, nums2 = {2, 2};
    vector<int> res = s.intersect(nums1, nums2);
    for (auto x: res) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}