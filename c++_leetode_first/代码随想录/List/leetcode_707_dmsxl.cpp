//
// Created by 11818 on 2024/12/20.
//

/**
 * leetcode 707:设计链表
 *
 *
 * */

#include <iostream>
using namespace std;

class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int v) : val(v), next(nullptr) {}
    };
    MyLinkedList() {
        _dummyNode = new ListNode(-1);
        _size = 0;
    }

    int get(int index) {
        if (index > (_size - 1) || index < 0) {
            return -1;
        }
        ListNode *cur = _dummyNode->next;
        while (index--) {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        ListNode *temp = new ListNode(val);
        ListNode *temp2 = _dummyNode->next;
        _dummyNode->next = temp;
        temp->next = temp2;
        _size++;
    }

    void addAtTail(int val) {
        ListNode *cur = _dummyNode;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        ListNode *temp = new ListNode(val);
        cur->next = temp;
        _size++;
    }

    void addAtIndex(int index, int val) {
        if (index > _size) return;
        if (index < 0) index = 0;
        ListNode *cur = _dummyNode;
        while (index--) {
            cur = cur->next;
        }
        ListNode *temp = new ListNode(val);
        ListNode *temp2 = cur->next;
        cur->next = temp;
        temp->next = temp2;
        _size++;
    }

    void deleteAtIndex(int index) {
        if (index >= _size || index < 0) {
            return;
        }
        ListNode *cur = _dummyNode;
        while (index--) {
            cur = cur->next;
        }
        ListNode *tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        tmp = nullptr;
        _size--;
    }

    void printLinkedList() {
        ListNode *cur = _dummyNode;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

private:
    ListNode *_dummyNode;
    int _size;
};

int main() {
    MyLinkedList *obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtHead(1);
    obj->addAtHead(3);
    obj->addAtIndex(1, 2);
    cout << obj->get(1) << endl;
    obj->deleteAtIndex(1);
    cout << obj->get(1) << endl;
    obj->printLinkedList();
    return 0;
}