#include <cstring>
#include <iostream>
#include <string>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 处理序列化的功能函数（递归）
    void SerializeFunction(TreeNode *root, std::string &str) {
        if (root == NULL) {
            str += '#';
            return;
        }
        std::string temp = std::to_string(root->val);
        str += temp + '!';// 加!，区分节点
        SerializeFunction(root->left, str);
        SerializeFunction(root->right, str);
    }

    char *Serialize(TreeNode *root) {
        if (root == NULL)
            return strdup("#");
        std::string res;
        SerializeFunction(root, res);
        char *charRes = new char[res.length() + 1];
        strcpy(charRes, res.c_str());
        charRes[res.length()] = '\0';
        return charRes;
    }

    // 处理反序列化的功能函数（递归）
    TreeNode *DeserializeFunction(const char **str) {
        if (**str == '#') {
            (*str)++;
            return NULL;
        }
        int val = 0;
        while (**str != '!' && **str != '\0') {
            val = val * 10 + ((**str) - '0');
            (*str)++;
        }
        TreeNode *root = new TreeNode(val);
        if (**str == '\0')
            return root;
        else
            (*str)++;
        root->left = DeserializeFunction(str);
        root->right = DeserializeFunction(str);
        return root;
    }

    TreeNode *Deserialize(const char *str) {
        if (strcmp(str, "#") == 0) {
            return NULL;
        }
        TreeNode *res = DeserializeFunction(&str);
        return res;
    }
};

std::ostream &printTree(TreeNode *root, std::ostream &os = std::cout) {
    if (root == NULL)
        os << "# ";
    else {
        os << root->val << " ";
        printTree(root->left, os);
        printTree(root->right, os);
    }
    return os;
}

int main() {
    std::string cur = "4!2!7!1!3!6!#!";
    Solution sol;
    TreeNode *root = sol.Deserialize(cur.c_str());
    std::cout << "Deserialize: " << std::endl;
    printTree(root);
    return 0;
}
