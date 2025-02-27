#include "BST/BST.hpp"
int main(){
    std::vector<int> a = {1,2,3,4,5,6};
    BSTree  root = (BSTree)malloc(sizeof(BSTNode));
    Creat_BST(root,a,a.size());
    get_vec(root);
    output_vec();
    BSTree new_root = DeleteNode(root,2);
    get_vec(new_root);
    output_vec();

    return 0;
}