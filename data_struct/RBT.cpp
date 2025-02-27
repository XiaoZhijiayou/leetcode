#include "RBT/RBT.hpp"
#include <iostream>

int main() {
    // Create a Red-Black Tree instance
    RBTree<int> rbTree;

    // Insert elements
    rbTree.insert(10);
    rbTree.insert(40);
    rbTree.insert(30);
    rbTree.insert(60);
    rbTree.insert(90);
    rbTree.insert(70);
    rbTree.insert(20);
    rbTree.insert(50);
    rbTree.insert(80);

    // Test pre-order traversal
    std::cout << "Pre-order Traversal: ";
    rbTree.preOrder(); // Expected output: Elements in pre-order sequence

    // Test in-order traversal
    std::cout << "In-order Traversal: ";
    rbTree.inOrder(); // Expected output: Elements in sorted order

    // Test post-order traversal
    std::cout << "Post-order Traversal: ";
    rbTree.postOrder(); // Expected output: Elements in post-order sequence

    // Test searching for a node (recursive and iterative)
    int searchKey = 30;
    RBTNode<int> *searchNode = rbTree.search(searchKey);
    if (searchNode != nullptr)
        std::cout << "Found node with key " << searchKey << " (recursive search)" << std::endl;
    else
        std::cout << "Node with key " << searchKey << " not found (recursive search)" << std::endl;

    searchNode = rbTree.iterativeSearch(searchKey);
    if (searchNode != nullptr)
        std::cout << "Found node with key " << searchKey << " (iterative search)" << std::endl;
    else
        std::cout << "Node with key " << searchKey << " not found (iterative search)" << std::endl;

    // Test minimum and maximum
    std::cout << "Minimum key in the tree: " << rbTree.minimum() << std::endl;
    std::cout << "Maximum key in the tree: " << rbTree.maximum() << std::endl;

    // Successor and Predecessor of a node
    RBTNode<int> *node = rbTree.search(50);
    RBTNode<int> *succ = rbTree.successor(node);
    if (succ != nullptr)
        std::cout << "Successor of node with key 50: " << succ->key << std::endl;
    else
        std::cout << "Successor of node with key 50 not found." << std::endl;

    RBTNode<int> *pred = rbTree.predecessor(node);
    if (pred != nullptr)
        std::cout << "Predecessor of node with key 50: " << pred->key << std::endl;
    else
        std::cout << "Predecessor of node with key 50 not found." << std::endl;

    // Test deleting a node
    std::cout << "Deleting node with key 40" << std::endl;
    rbTree.remove(40);
    
    // Test in-order traversal after deletion
    std::cout << "In-order Traversal after deletion: ";
    rbTree.inOrder();

    return 0;
}
