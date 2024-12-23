//
// Created by 11818 on 2024/12/22.
//

/**
 * leetcode_142:环形链表 ||
 *  给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
 *
 * */
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


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            /// 当快慢指针相遇的时候，开始让快指针从相遇点开始，慢指针从出发点开始，都走相同的步数1
            if (slow == fast) {
                slow = head;
                while (fast != slow) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};