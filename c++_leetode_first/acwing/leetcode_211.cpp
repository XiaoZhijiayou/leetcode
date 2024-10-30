//
// Created by 11818 on 2024/10/26.
//

#include <iostream>
#include <string>
using namespace std;

class WordDictionary {
public:
    //先定义一个串
    struct Node {
        bool isEnd = false;
        Node *son[26];
        Node() {
            isEnd = false;
            for (int i = 0; i < 26; i++) son[i] = nullptr;
        }
    } *root;

    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        auto p = root;
        for (auto c: word) {
            int u = c - 'a';
            if (!p->son[u]) p->son[u] = new Node();
            p = p->son[u];
        }
        p->isEnd = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
    bool dfs(string word, int i, Node *p) {
        if (i == word.size()) {
            return p->isEnd;
        }
        if (word[i] != '.') {
            int u = word[i] - 'a';
            if (!p->son[u])
                return false;
            return dfs(word, i + 1, p->son[u]);
        } else {
            for (int j = 0; j < 26; j++) {
                if (p->son[j] && dfs(word, i + 1, p->son[j]))
                    return true;
                //如果把这个改为return(p->son[j] && dfs(word,i + 1,p->son[j]));这个的话
                //就会产生不会把所有的26个字母遍历完全的情况
                //这是因为如果对于第一个j不成立的话就会直接返回false不会进行往下的遍历!!!!
            }
            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
int main() {
    auto sol = new WordDictionary();
    sol->addWord("bad");
    sol->addWord("dad");
    sol->addWord("mad");
    cout << sol->search("pad") << endl;// false
    cout << sol->search("bad") << endl;// true
    cout << sol->search(".ad") << endl;// true
    cout << sol->search("b..") << endl;// true
    return 0;
}
