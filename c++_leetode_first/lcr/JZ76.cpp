//
// Created by 11818 on 2024/7/15.
//

#include <cstring>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {
    }
};

//#include <climits>
class Solution {
public:
    ListNode *deleteDuplication(ListNode *pHead) {
        ListNode *vitual_node = new ListNode(0);
        vitual_node->next = pHead;
        ListNode *cur = vitual_node;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            //寻找当前节点有无重复节点
            if (cur->next->val == cur->next->next->val) {
                int temp = cur->next->val;
                while (cur->next != nullptr && cur->next->val == temp) {
                    cur->next = cur->next->next;
                }
            } else {
                cur = cur->next;
            }
        }
        return vitual_node->next;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next = new ListNode(5);
    ListNode *res = s.deleteDuplication(head);
    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}