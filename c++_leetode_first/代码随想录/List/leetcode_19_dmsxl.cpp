//
// Created by 11818 on 2024/12/22.
//

/**
 * leetcode19:删除链表的倒数第N个节点
 * 方法：快慢指针的方法
 * 保持快慢指针之间的差距是固定的
 * 其中的快指针需要与慢指针之间保持n + 1个之间的差距
 * 其中是让fast到达nullptr部分，然后正好慢指针对应到要删除块的前一个部分
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

ListNode *build_List(std::vector<int> vec) {
    if (vec.empty()) {
        return nullptr;// 如果输入的向量为空，返回空指针
    }

    ListNode *head = new ListNode(vec[0]);// 创建头节点
    ListNode *current = head;             // 使用current指针来遍历链表

    for (int i = 1; i < vec.size(); i++) {
        ListNode *temp = new ListNode(vec[i]);// 创建新节点
        current->next = temp;                 // 将当前节点的next指向新节点
        current = temp;                       // 更新current指针到新节点
    }

    return head;// 返回头节点
}

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *slow = dummy;
        ListNode *fast = dummy;
        while (n-- && fast != nullptr) {
            fast = fast->next;
        }
        fast = fast->next;
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *temp = slow->next->next;
        slow->next = temp;
        return dummy->next;
    }
};


int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    ListNode *head = build_List(vec);
    int n = 2;
    Solution s;
    ListNode *cur = s.removeNthFromEnd(head, n);
    cout << " " << endl;
    return 0;
}