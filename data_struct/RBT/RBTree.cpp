#include "RBT.hpp"


// Maximum node search
template<class T>
T RBTree<T>::maximum() {
    RBTNode<T>* node = maximum(mRoot);
    if (node)
        return node->key;
    return T(); // return default value if no node
}

// Remove a node with the given key
template<class T>
void RBTree<T>::remove(T key) {
    RBTNode<T>* node = search(mRoot, key);
    if (node != nullptr)
        remove(mRoot, node);
}

// Find the successor of the node
template<class T>
RBTNode<T>* RBTree<T>::successor(RBTNode<T>* x) {
    if (x->right != nullptr)
        return minimum(x->right);
    RBTNode<T>* y = x->parent;
    while (y != nullptr && x == y->right) {
        x = y;
        y = y->parent;
    }
    return y;
}

// Find the predecessor of the node
template<class T>
RBTNode<T>* RBTree<T>::predecessor(RBTNode<T>* x) {
    if (x->left != nullptr)
        return maximum(x->left);
    RBTNode<T>* y = x->parent;
    while (y != nullptr && x == y->left) {
        x = y;
        y = y->parent;
    }
    return y;
}

// Don't forget to implement minimum(), maximum(), and recursive/iterative search helpers
