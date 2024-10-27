#include <iostream>

using namespace std;

// Definition for a binary tree node.
  struct TreeNode {
 	int val;
 	struct TreeNode *left;
 	struct TreeNode *right;
 	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param proot TreeNode类
     * @param k int整型
     * @return int整型
     */
    int count = 0;
    TreeNode* result = nullptr;
    void dg(TreeNode* root,int k){
        if(root == nullptr || count > k)
            return;
        dg(root->left, k);
        count++;
        if(count == k)
            result = root;
        dg(root->right,k);
    }
    int KthNode(TreeNode* proot, int k) {
        // write code here
        dg(proot,k);
        if(result)
            return result->val;
        else
            return -1;
    }
};

// 测试代码
int main() {
    Solution s;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);
    int k = 3;
    cout << s.KthNode(root, k) << endl; // 4
    return 0;
}