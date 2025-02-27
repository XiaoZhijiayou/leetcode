#ifndef AVL_H
#define AVL_H

#include <utility>
#include <iostream>
#include <cassert>
#include <string>

template<class K, class V>
struct AVLNode {
    AVLNode<K, V>* _left;
    AVLNode<K, V>* _right;
    AVLNode<K, V>* _parent;
    int _bf;
    std::pair<K, V> _kv;
    explicit AVLNode(const std::pair<K, V>& kv)
        : _left(nullptr), _right(nullptr), _parent(nullptr), _bf(0), _kv(kv) {}
};

template <class K, class V>
class AVLTree {
    typedef AVLNode<K, V> Node;

public:
    AVLTree() : _root(nullptr) {}
    bool insert(const std::pair<K, V>& kv);
    bool Find(const K& k);
    void InOrder() const;

private:
    void RotateL(Node* parent);
    void RotateR(Node* parent);
    void RotateLR(Node* parent);
    void RotateRL(Node* parent);
    void _InOrder(Node* node) const;

    Node* _root;
};

// 函数实现部分

template <class K, class V>
bool AVLTree<K, V>::insert(const std::pair<K, V>& kv) {
    if (_root == nullptr) {
        _root = new Node(kv);
        return true;
    }

    Node* cur = _root;
    Node* parent = nullptr;

    while (cur) {
        parent = cur;
        if (cur->_kv.first > kv.first)
            cur = cur->_left;
        else if (cur->_kv.first < kv.first)
            cur = cur->_right;
        else
            return false; // 不允许插入重复的节点
    }

    cur = new Node(kv);
    cur->_parent = parent;
    if (cur->_kv.first > parent->_kv.first)
        parent->_right = cur;
    else
        parent->_left = cur;

    while (parent) {
        if (cur == parent->_right)
            parent->_bf++;
        else
            parent->_bf--;

        if (parent->_bf == 0) {
            break;
        } else if (parent->_bf == 1 || parent->_bf == -1) {
            cur = parent;
            parent = parent->_parent;
        } else if (parent->_bf == 2 || parent->_bf == -2) {
            if (parent->_bf == 2 && cur->_bf == 1)
                RotateL(parent);
            else if (parent->_bf == -2 && cur->_bf == -1)
                RotateR(parent);
            else if (parent->_bf == -2 && cur->_bf == 1)
                RotateLR(parent);
            else if (parent->_bf == 2 && cur->_bf == -1)
                RotateRL(parent);
            break;
        } else {
            assert(false);
        }
    }
    return true;
}

template <class K, class V>
void AVLTree<K, V>::RotateL(Node* parent) {
    Node* grandparent = parent->_parent;
    Node* subR = parent->_right;
    Node* subRL = subR->_left;

    parent->_right = subRL;
    if (subRL)
        subRL->_parent = parent;

    subR->_left = parent;
    parent->_parent = subR;

    if (grandparent == nullptr) {
        _root = subR;
        subR->_parent = nullptr;
    } else {
        if (parent == grandparent->_left)
            grandparent->_left = subR;
        else
            grandparent->_right = subR;
        subR->_parent = grandparent;
    }

    parent->_bf = subR->_bf = 0;
}

template <class K, class V>
void AVLTree<K, V>::RotateR(Node* parent) {
    Node* subL = parent->_left;
    Node* grandparent = parent->_parent;
    Node* subLR = subL->_right;

    parent->_left = subLR;
    if (subLR)
        subLR->_parent = parent;

    subL->_right = parent;
    parent->_parent = subL;

    if (grandparent == nullptr) {
        _root = subL;
        subL->_parent = nullptr;
    } else {
        if (parent == grandparent->_left)
            grandparent->_left = subL;
        else
            grandparent->_right = subL;
        subL->_parent = grandparent;
    }

    parent->_bf = subL->_bf = 0;
}

template <class K, class V>
void AVLTree<K, V>::RotateLR(Node* parent) {
    Node* subL = parent->_left;
    Node* subLR = subL->_right;
    int lrbf = subLR->_bf;

    RotateL(subL);
    RotateR(parent);

    if (lrbf == 0) {
        parent->_bf = subL->_bf = subLR->_bf = 0;
    } else if (lrbf == -1) {
        subL->_bf = subLR->_bf = 0;
        parent->_bf = 1;
    } else if (lrbf == 1) {
        subL->_bf = -1;
        subLR->_bf = parent->_bf = 0;
    } else {
        assert(false);
    }
}

template <class K, class V>
void AVLTree<K, V>::RotateRL(Node* parent) {
    Node* subR = parent->_right;
    Node* subRL = subR->_left;
    int rlbf = subRL->_bf;

    RotateR(subR);
    RotateL(parent);

    if (rlbf == 0) {
        subR->_bf = subRL->_bf = parent->_bf = 0;
    } else if (rlbf == -1) {
        subRL->_bf = parent->_bf = 0;
        subR->_bf = 1;
    } else if (rlbf == 1) {
        parent->_bf = -1;
        subR->_bf = subRL->_bf = 0;
    } else {
        assert(false);
    }
}

template <class K, class V>
bool AVLTree<K, V>::Find(const K& k) {
    Node* cur = _root;
    while (cur) {
        if (cur->_kv.first > k)
            cur = cur->_left;
        else if (cur->_kv.first < k)
            cur = cur->_right;
        else
            return true;
    }
    return false;
}

template <class K, class V>
void AVLTree<K, V>::InOrder() const {
    _InOrder(_root);
    std::cout << std::endl;
}

template <class K, class V>
void AVLTree<K, V>::_InOrder(Node* node) const {
    if (node == nullptr) return;
    _InOrder(node->_left);
    std::cout << node->_kv.first << ": " << node->_kv.second << " ";
    _InOrder(node->_right);
}

#endif // AVL_H




