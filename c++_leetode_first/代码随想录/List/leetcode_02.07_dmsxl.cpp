//
// Created by 11818 on 2024/12/22.
//
/**
 *  面试题02.07 链表相交
 *  给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null。
 *
 *  思路：
 *      1.先把两个链表的长度确定下来，然后让比较长的部分移动到对应的
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA;
        ListNode *curB = headB;
        size_t length_A = 0;
        size_t length_B = 0;
        while (curA->next != nullptr) {
            curA = curA->next;
            length_A++;
        }
        while (curB->next != nullptr) {
            curB = curB->next;
            length_B++;
        }
        /// 得到长度之后，将较长的移动gap个位置
        curA = headA;
        curB = headB;
        if (length_B > length_A) {
            swap(length_A, length_B);
            swap(curA, curB);
        }
        /// 其实就是为了让curA是最长的那个串
        int gap = length_A - length_B;
        while (gap--) {
            curA = curA->next;
        }
        /// 遍历curA和curB，遇到相同的直接返回
        while (curA != nullptr) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
};

int main() {
    return 0;
}