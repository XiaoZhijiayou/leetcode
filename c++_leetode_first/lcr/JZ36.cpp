//
// Created by 11818 on 2024/7/25.
//
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    vector<TreeNode *> dp;
    void inorder(TreeNode *root) {
        if (root == nullptr) return;
        inorder(root->left);
        dp.push_back(root);
        inorder(root->right);
    }
    TreeNode *Convert(TreeNode *pRootOfTree) {
        if (pRootOfTree == nullptr) return nullptr;
        inorder(pRootOfTree);
        for (int i = 0; i < dp.size() - 1; i++) {
            dp[i]->right = dp[i + 1];
            dp[i + 1]->left = dp[i];
        }
        return dp[0];
    }
};
ostream &operator<<(ostream &os, const TreeNode *root) {
    if (root == nullptr) return os;
    while (root != nullptr) {
        os << root->val << " ";
        root = root->right;
    }
    return os;
}

int main() {
    Solution s;
    //这是一个二叉搜索树
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    TreeNode *newRoot = s.Convert(root);
    cout << newRoot << endl;
    return 0;
}