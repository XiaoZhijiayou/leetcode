//
// Created by 11818 on 2024/7/15.
//

#include <iostream>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

#include <unordered_map>
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if(pHead == nullptr)
            return pHead;
        //先添加一个随机的开始节点
        RandomListNode* result =  new RandomListNode(0);
        unordered_map<RandomListNode* , RandomListNode*> mp; ///这里面存储的是原始链表节点和对应的clone的新节点，这两个节点是一一对应的关系
        RandomListNode* cur = pHead;
        RandomListNode* pre = result;
        while(cur != nullptr){
            RandomListNode* clone = new RandomListNode(cur->label);
            pre->next = clone;
            mp[cur] = clone;
            pre = pre->next;
            cur = cur->next;
        }
        //便利哈希表
        for(auto node : mp){
            if(node.first->random == nullptr)
                node.second->random = nullptr;
            else
                node.second->random = mp[node.first->random];
        }
        return result->next;
    }
};

int main() {
    Solution s;
    RandomListNode* p1 = new RandomListNode(1);
    RandomListNode* p2 = new RandomListNode(2);
    RandomListNode* p3 = new RandomListNode(3);
    RandomListNode* p4 = new RandomListNode(4);
    RandomListNode* p5 = new RandomListNode(5);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p1->random = p3;
    p2->random = p5;
    p3->random = p2;
    p4->random = p4;
    p5->random = p1;
    RandomListNode* p6 = s.Clone(p1);
    while(p6!= nullptr){
        cout<<p6->label<<" ";
        p6 = p6->next;

    }

    return 0;
}