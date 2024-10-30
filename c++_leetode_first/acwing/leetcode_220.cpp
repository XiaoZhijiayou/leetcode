//
// Created by 11818 on 2024/10/29.
//
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        typedef long long LL;
        multiset<LL> S;
        S.insert(1e18), S.insert(-1e18);
        //这个方法是维护一个数组的方法：就是维护一个从i到j的数组的一个方法
        for (int i = 0, j = 0; i < nums.size(); i++) {
            if (i - j > k) S.erase(S.find(nums[j++]));//这个操作是为了维持这个multset里面维护的是i j之内的nums值
            //这个也就在一方面保证了里面的数组的值的下标不会越界的结果，j是左窗口，i右边窗口
            int x = nums[i];
            auto it = S.lower_bound(x);//第一个大于等于x的迭代器位置部分
            //之所以这么取是为了保证能够取到最接近x的部分！！！
            if (*it - x <= t) return true;
            --it;//相见之后就是变成了最后一个小于x的迭代器位置部分
            if (x - *it <= t) return true;
            S.insert(x);
        }
        return false;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1};
    int indexDiff = 3;
    int valueDiff = 0;
    Solution s;
    cout << s.containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff);
    return 0;
}