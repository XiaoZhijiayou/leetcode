//
// Created by 11818 on 2024/10/27.
//
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> st;
        for (auto c: nums) {
            if (st.count(c)) return true;
            st.insert(c);
        }
        return false;
    }
};
int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 1};
    cout << s.containsDuplicate(nums) << endl;
    return 0;
}
//unordered_set 是 C++ 标准库中的容器，和 set 类似，但底层是基于哈希表（hash table）实现的\
//性质
//1.元素无序性：unordered_set 中的元素是无序的，插入的顺序与存储顺序不一定一致。
//2.唯一性：unordered_set 中的元素必须是唯一的，即不能有重复元素。
//3.高效查找：基于哈希表的实现，使得 unordered_set 查找、插入和删除的时间复杂度平均为𝑂(1)O(1)。
//4.无序性但恒定性：虽然元素无序，但同一组元素在不同运行中，unordered_set 的顺序可能是恒定的（但在不同编译器或编译器版本下可能不同）。
//操作
//1.插入元素：uset.insert(6);
//2.查找元素：uset.find(3)
//3.删除元素 uset.erase(4);
