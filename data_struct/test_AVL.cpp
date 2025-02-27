#include "AVL.h"// assuming you have the AVLTree class in a header file called avl_tree.h
#include <iostream>
#include <string>
#include <utility>

int main() {
    // Create an AVL Tree object
    AVLTree<int, std::string> avlTree;

    // Test Insertions
    std::cout << "Inserting elements into the AVL Tree:" << std::endl;
    avlTree.insert(std::make_pair(10, "ten"));
    avlTree.insert(std::make_pair(20, "twenty"));
    avlTree.insert(std::make_pair(5, "five"));
    avlTree.insert(std::make_pair(15, "fifteen"));
    avlTree.insert(std::make_pair(25, "twenty-five"));
    avlTree.insert(std::make_pair(2, "two"));
    avlTree.insert(std::make_pair(8, "eight"));

    std::cout << "Elements inserted successfully." << std::endl;

    // Test search function
    std::cout << "Testing search function:" << std::endl;
    if (avlTree.Find(10))
        std::cout << "Found key 10." << std::endl;
    else
        std::cout << "Key 10 not found." << std::endl;

    if (avlTree.Find(15))
        std::cout << "Found key 15." << std::endl;
    else
        std::cout << "Key 15 not found." << std::endl;

    if (avlTree.Find(30))
        std::cout << "Found key 30." << std::endl;
    else
        std::cout << "Key 30 not found." << std::endl;

    // Test tree height function
    // std::cout << "The height of the AVL tree is: " << avlTree._Height(avlTree._root) << std::endl;

    // Test InOrder Traversal
    std::cout << "In-order traversal of the AVL Tree:" << std::endl;
    avlTree.InOrder();

    return 0;
}
