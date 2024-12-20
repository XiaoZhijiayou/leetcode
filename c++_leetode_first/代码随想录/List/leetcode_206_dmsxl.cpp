//
// Created by 11818 on 2024/12/20.
//
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
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur != nullptr) {
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
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
    std::vector<int> vec = {1, 2, 3, 4, 5};
    ListNode *cur = build_List(vec);
    ListNode *res = s.reverseList(cur);
    cout << res->val << std::endl;
    return 0;
}