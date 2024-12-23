//
// Created by 11818 on 2024/12/22.
//

#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> result_set;
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (auto num: nums2) {
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};


/**
 * 下面就是对于set、unordered_set
 * */

/// set本身是由红黑树构成的
template<typename T>
std::ostream &operator<<(std::ostream &out, const std::set<T> &set) {
    if (set.empty())
        return out << "{}";
    out << "{ " << *set.begin();
    std::for_each(std::next(set.begin()), set.end(), [&out](const T &element) {
        out << ", " << element;
    });
    return out << " }";
}

void test_set() {
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(1);
    cout << "set 中 1 出现的次数是：" << s.count(1) << endl;
    /// equal_range() ：返回一对定位器，分别表示第一个大于或等于给定关键值的元素和 第一个大于给定关键值的元素，
    /// 这个返回值是一个pair类型，如果这一对定位器中哪个返回失败，就会等于end()的值。
    auto pr = s.equal_range(3);
    cout << "第一个大于等于 3的数是：" << *pr.first << endl;
    cout << "第一个大于   3的数是 ：" << *pr.second << endl;
    /// erase(iterator)  ,删除定位器iterator指向的值
    /// erase(first,second),删除定位器first和second之间的值
    /// erase(key_value),删除键值key_value的值
    s.erase(3);
    for (auto i: s) {
        cout << i << " ";
    }
    cout << endl;
    /// lower_bound(key_value) ，返回第一个大于等于key_value的定位器
    /// upper_bound(key_value)，返回最后一个大于等于key_value的定位器
    std::set<int> set{1, 5, 3};
    std::cout << set << '\n';
    //    std::cout << set.contains(3) << endl;
}

void test_unordered_set() {
}

int main() {

    return 0;
}