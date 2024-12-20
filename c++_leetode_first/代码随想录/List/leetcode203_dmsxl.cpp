//
// Created by 11818 on 2024/12/20.
//

/**
 * leetcode 203:移除链表元素
 *
 * 给你一个链表的头节点 head 和一个整数 val ，
 * 请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
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
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *dummyNode = new ListNode(-1, head);
        ListNode *cur = dummyNode;
        while (cur->next != nullptr) {
            if (cur->next->val == val) {
                ListNode *next = cur->next;
                cur->next = cur->next->next;
                delete next;
            } else {
                cur = cur->next;
            }
        }
        return dummyNode->next;
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
    Solution s;
    std::vector<int> vec = {1, 2, 6, 3, 4, 5, 6};
    int val = 6;
    ListNode *temp = build_List(vec);
    ListNode *res = s.removeElements(temp, val);
    cout << "hello";
    return 0;
}