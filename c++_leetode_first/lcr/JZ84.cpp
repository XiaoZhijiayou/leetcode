//
// Created by 11818 on 2024/7/26.
//

#include <iostream>
#include <memory>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int count_num = 0;

    void count_dfs(TreeNode *root, int sum, int cur_sum) {
        if (root == nullptr) return;

        cur_sum += root->val;

        if (cur_sum == sum) count_num++;

        count_dfs(root->left, sum, cur_sum);
        count_dfs(root->right, sum, cur_sum);

        return;
    }

    void dfs(TreeNode *root, int sum) {
        if (root == nullptr) return;

        count_dfs(root, sum, 0);// 注意这里的cur_sum初始化为0,算的是从当前节点的路径开始的和
        dfs(root->left, sum);   //下来走的就是从当前节点的左子树开始的路径
        dfs(root->right, sum);  //右子树的路径
        return;
    }

    int FindPath(TreeNode *root, int sum) {
        dfs(root, sum);
        return count_num;
    }
};

int main() {
    shared_ptr<TreeNode> root1(new TreeNode(10));
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);


    root->right = new TreeNode(-3);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(11);

    Solution s;
    int sum = 8;
    cout << s.FindPath(root, sum) << endl;

    return 0;
}