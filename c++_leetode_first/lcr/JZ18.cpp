//
// Created by 11818 on 2024/7/15.
//
#include <iostream>
#include <cmath>
using namespace std;


// Definition for singly-linked list.
  struct ListNode {
 	int val;
 	struct ListNode *next;
 	ListNode(int x) : val(x), next(nullptr) {}
  };

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @param val int整型
     * @return ListNode类
     */
    ListNode* deleteNode(ListNode* head, int val) {
        // write code here
        ListNode* virtual_node = new ListNode(0);
        virtual_node->next = head;
        ListNode* cur = virtual_node;
        while(cur->next != nullptr){
            if(cur->next->val == val){
                cur->next = cur->next->next;
            }else{
                cur = cur->next;
            }
        }
        return virtual_node->next;
    }
};

int main(){
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    int val = 3;
    ListNode* res = s.deleteNode(head, val);
    while(res != nullptr){
        cout<<res->val<<" ";
        res = res->next;
    }
    return 0;
}