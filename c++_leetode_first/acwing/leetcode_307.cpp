//
// Created by 11818 on 2024/11/17.
//
#include <iostream>
#include <vector>
using namespace std;
//这里涉及了树状数组
class NumArray {
public:
    int n;
    vector<int> tr, nums;

    int lowbit(int x) {
        return x & -x;
    }

    int query(int x) {
        int res = 0;
        for (int i = x; i; i -= lowbit(i)) res += tr[i];
        return res;
    }

    void add(int x, int v) {
        for (int i = x; i <= n; i += lowbit(i)) tr[i] += v;
    }

    NumArray(vector<int> &_nums) {
        nums = _nums;
        n = nums.size();
        tr.resize(n + 1);

        for (int i = 0; i < n; i++) add(i + 1, nums[i]);
    }

    void update(int i, int val) {
        add(i + 1, val - nums[i]);
        nums[i] = val;
    }

    int sumRange(int i, int j) {
        return query(j + 1) - query(i);
    }
};

int main() {
    vector<int> nums = {1, 3, 5};
    NumArray *obj = new NumArray(nums);
    int param_2 = obj->sumRange(0, 2);
    obj->update(1, 2);
    int param_3 = obj->sumRange(0, 2);
    cout << "1: " << param_2 << "   2: " << param_3 << endl;
    return 0;
}