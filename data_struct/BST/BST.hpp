#pragma once
//二叉排序树的结点
#include <iostream>
#include <vector>
typedef struct BSTNode
{
    int key;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;


//在二插排序树中查找值为key的结点：空间复杂度：O(1)
BSTNode* BST_Search(BSTree T, int key) {
    while(T != nullptr && key != T->key) {
        if(key < T->key) {
            T = T->lchild;  // Move to the left child if key is smaller
        } else {
            T = T->rchild;  // Move to the right child if key is greater
        }
    }
    return T;
}
// //递归的方法写：空间复杂度：O(h) H代表高度
// BSTNode* BST_Search(BSTree T,int key){
//     if(T == nullptr)
//         return nullptr;
//     if(key == T->key)
//         return T;
//     else if(key < T->key)
//         return BST_Search(T->lchild,key);
//     else
//         return  BST_Search(T->rchild,key);
// }

//插入操作：(最坏空间复杂度O(h)),在二叉排序树插入关键词为k的新节点
int BST_Insert(BSTree &T,int k){
    if(T == nullptr){
        T = (BSTree)malloc(sizeof(BSTNode));
        T->key = k;
        T->lchild = nullptr;
        T->rchild = nullptr;
        return 1;//返回1，插入成功
    }
    else if(T->key == k)    
            return 0;//树中已存在这个节点，插入失败
    else if(k < T->key)
        return BST_Insert(T->lchild,k);
    else
        return BST_Insert(T->rchild,k);
}

//按照vector<int>形式插入建立二叉排序数组
void Creat_BST(BSTree &T,std::vector<int>& a,int n){
    T=nullptr;
    int i = 0;
    while(i < n){   //依次将每个关键字插入到二叉排序树中
        BST_Insert(T,a[i]);
        i++;
    }
}

static std::vector<BSTree> in_order_traversal_vec;
void in_order_travel(BSTree& root){
    if(root == nullptr)
        return ;
    in_order_travel(root->lchild);
    in_order_traversal_vec.push_back(root);
    in_order_travel(root->rchild);
}

void get_vec(BSTree& T){
    in_order_traversal_vec.clear();
    in_order_travel(T);
}
void output_vec(){
    for(int i = 0; i < in_order_traversal_vec.size();i++){
        std::cout<< in_order_traversal_vec[i]->key <<"  ";
        if(i == in_order_traversal_vec.size() - 1)
            std::cout << std::endl;
    }
}

// 查找BST中的最小值节点
BSTree FindMin(BSTree root) {
    if (root == nullptr) {
        return nullptr; // 如果树为空，返回nullptr
    }
    while (root->lchild != nullptr) {
        root = root->lchild; // 一直向左子树移动，直到找到最左边的节点
    }
    return root; // 返回最左边的节点，它是最小值节点
}


BSTree DeleteNode(BSTree &root,int k){
    if(root == nullptr){
        return nullptr; //空树或者找不到值为k的节点
    }
    if(k < root->key){
        root->lchild = DeleteNode(root->lchild,k);
    }else if(k > root->key){
        root->rchild = DeleteNode(root->rchild,k);
    }else{
        //找到了值为k的节点
        if(root->lchild == nullptr){
            BSTree temp = root->rchild;
            delete root;
            return temp;
        }
        else if(root->rchild == nullptr){
            BSTree temp = root->lchild;
            delete root;
            return temp;            
        }else {
            //有两个子树
            //这段代码的意思是：如果两边子树都有，先将当前root的key值转换为右子树的最小那个节点的值，
            //然后再去把这个右子树最小值删去，这时候删去这个值只需要利用上上面那种左右子树没有的情况就可以了，直接删除当前节点
            BSTree successor = FindMin(root->rchild);
            root->key = successor->key;
            root->rchild = DeleteNode(root->rchild,successor->key);
        }
    }
    return root;
}

