//
// Created by 11818 on 2024/10/31.
//
//LCR124:推理二叉树
#include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode *deduceTree(vector<int> &preorder, vector<int> &inorder) {
        if (inorder.size() == 0)
            return nullptr;
        unordered_map<int, int> hash;
        int n = inorder.size();
        for (int i = 0; i < inorder.size(); i++) {
            hash[inorder[i]] = i;
        }
        function<TreeNode *(int, int, int)> dfs = [&](int index_pre, int index_in, int length) -> TreeNode * {
            if (length <= 0)
                return nullptr;
            int k = hash[preorder[index_pre]];//这个是有序遍历中的根结点的下标
            int l = k - index_in;             //这个是左子树的长度
            TreeNode *root = new TreeNode(preorder[index_pre]);
            root->left = dfs(index_pre + 1, index_in, l);//其中这个长度部分是左子树的长度length
            root->right = dfs(l + 1 + index_pre, k + 1, length - l - 1);
            return root;
        };
        return dfs(0, 0, n);
    }
    void inorder_dfs(TreeNode *root) {
        if (root == nullptr)
            return;
        inorder_dfs(root->left);
        cout << root->val << " ";
        inorder_dfs(root->right);
        return;
    }
};

int main() {
    Solution s;
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    TreeNode *result = s.deduceTree(preorder, inorder);
    s.inorder_dfs(result);
}