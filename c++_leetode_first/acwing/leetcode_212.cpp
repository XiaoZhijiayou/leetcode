//
// Created by 11818 on 2024/10/26.
//
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
//这个题目还是利用一个Trie树来实现的
class Solution {
public:
    struct Node {
        int id;//这个表示是第几个字符串
        Node *son[26];
        Node() {
            id = -1;//表示没有开始
            for (int i = 0; i < 26; i++) {
                son[i] = nullptr;
            }
        }
    };
    Node *root;

    void insert(string word, int id) {
        Node *p = root;
        for (char c: word) {
            int u = c - 'a';
            if (!p->son[u]) p->son[u] = new Node();
            p = p->son[u];
        }
        p->id = id;
    }
    //这个Trie树的作用就是将words里面每个字符串绑定起来，对应上每一个值
    //开始取全局变量
    unordered_set<string> hash;
    vector<string> ans;
    vector<vector<bool>> st;//这个是在当前的word字符串下有没有重复遍历其中的字符
    vector<string> _words;  //这个是用来存储words的
    int n, m;               //这个分别用来存储长和宽

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        if (board.size() == 0) return ans;
        _words = words;
        root = new Node();//开始进行插入字符串
        for (int i = 0; i < words.size(); i++) insert(words[i], i);
        n = board.size(), m = board[0].size();
        st = vector<vector<bool>>(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                dfs(board, i, j, root->son[board[i][j] - 'a']);//这个就是开始遍历的起点
        return ans;
    }
    void dfs(vector<vector<char>> &board, int x, int y, Node *u) {
        if (!u) return;//如果这个当前位置的值不存在在这个Trie树里面的话，就直接返回就好
        //下来就是存在的策略了
        st[x][y] = true;
        //先将这个部分进行一下覆盖
        if (u->id != -1) {
            //这点的逻辑就是这个点处是根节点的话，该如何去做
            string match = _words[u->id];
            //查询这个当前绑定的string是什么？
            if (!hash.count(match)) {
                hash.insert(match);
                ans.push_back(match);
                //之所有要用这个hash也就是因为不要重复输出这个相同的字符串的道理！！
            }
        }
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        //再将各个方向的xy变化加上
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && !st[a][b]) {
                //就是看看下表有没有越界和这个位置有没有遍历过
                char c = board[a][b];
                dfs(board, a, b, u->son[c - 'a']);
            }
        }
        //然后将这个st[x][y]的覆盖再去掉
        st[x][y] = false;
    }
};
int main() {
    Solution s;
    vector<vector<char>> board = {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    vector<string> words = {"oath", "pea", "eat", "rain"};
    vector<string> res = s.findWords(board, words);
    for (string str: res)
        cout << str << endl;
    return 0;
}