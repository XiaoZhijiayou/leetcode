//
// Created by 11818 on 2024/11/13.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int a = 0;
        int b = 0;
        while (true) {
            a = nums[a];
            b = nums[nums[b]];
            if (a == b) {
                a = 0;
                while (a != b) {
                    a = nums[a];
                    b = nums[b];
                }
                return a;
            }
        }
        return -1;
    }
};
//这个利用的就是环形表的思想
//一个快指针一个慢指针，如果里面有环部分，就会相遇，相遇之后将慢指针移动到头部，快指针还在原来位置，如果到了快慢指针的对应数相等时候
//就代表着得到了环的入口部分
//这样就表明了算法的思想部分
//还有为何会得到一个环，是因为nums数组里面有相等的数对应的就一定有环
int main() {
    Solution s;
    vector<int> nums = {1, 3, 4, 2, 2};
    cout << s.findDuplicate(nums) << endl;
    return 0;
}