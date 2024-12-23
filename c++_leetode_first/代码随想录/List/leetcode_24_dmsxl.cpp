//
// Created by 11818 on 2024/12/22.
//

/**
 * 24.两两交换链表中的节点
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
    ListNode *swapPairs(ListNode *head) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode *temp = cur->next;
            ListNode *temp1 = cur->next->next->next;

            cur->next = cur->next->next;
            cur->next->next = temp;
            temp->next = temp1;

            cur = cur->next->next;
        }
        ListNode *result = dummy->next;
        delete dummy;
        return result;
    }
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

int main() {
    std::vector<int> vec = {1, 2, 3, 4};
    ListNode *head = build_List(vec);
    Solution s;
    ListNode *res = s.swapPairs(head);
    cout << "  " << endl;
    return 0;
}