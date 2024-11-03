//
// Created by 11818 on 2024/10/31.
//
//LCR123:图书整理|
#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//顺序遍历+反转
class Solution {
public:
    vector<int> reverseBookList(ListNode *head) {
        vector<int> result;
        for (; head; head = head->next) {
            result.push_back(head->val);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution s;
    ListNode *l0 = new ListNode(1);
    ListNode *l1 = new ListNode(4, l0);
    ListNode *l2 = new ListNode(6, l1);
    ListNode *l3 = new ListNode(3, l2);
    auto result = s.reverseBookList(l3);
    for (auto r: result) {
        cout << r << " ";
    }
    cout << endl;
    return 0;
}