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
    ListNode *trainingPlan(ListNode *head, int cnt) {
        //利用快慢指针的形式进行
        //保持快慢指针之间的距离为cnt个节点
        auto dummy = new ListNode(-1, head);
        auto slow = dummy;
        auto fast = dummy;
        while (cnt--) {
            fast = fast->next;
        }
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
