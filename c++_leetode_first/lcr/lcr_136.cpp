//
// Created by 11818 on 2024/11/24.
//
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode *deleteNode(ListNode *head, int val) {
        ListNode *dummy = new ListNode(0, head);
        for (ListNode *cur = dummy; cur->next; cur = cur->next) {
            if (cur->next->val == val) {
                cur->next = cur->next->next;
                break;
            }
        }
        return dummy->next;
    }
};

int main() {
    auto head = new ListNode(4, new ListNode(5, new ListNode(1, new ListNode(9))));
    Solution s;
    int val = 5;
    for (auto cur = s.deleteNode(head, 5); cur; cur = cur->next) {
        cout << cur->val << "  ";
    }
    cout << endl;
    return 0;
}