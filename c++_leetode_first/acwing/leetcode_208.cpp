//
// Created by 11818 on 2024/10/26.
//
//208.实现Trie(前缀树)
#include <string>
#include <iostream>
using namespace  std;

class Trie {
public:
    struct Node{
        Node* son[26];
        bool is_end;
        Node(){
            for(int i = 0; i < 26;i++) son[i] = NULL;
            is_end = false;
        }
    }*root;
    Trie():root(new Node()){}
    void insert(string word) {
        auto p = root;
        for(auto c : word){
            int u = c - 'a';
            if(!p->son[u])  p->son[u] = new Node();
            p = p->son[u];
        }
        p->is_end = true;
    }

    bool search(string word) {
        auto p = root;
        for(auto c : word){
            int u = c - 'a';
            if(!p->son[u])  return false;
            p = p->son[u];
        }
        return p->is_end;
    }

    bool startsWith(string prefix) {
        auto p = root;
        for(auto c : prefix){
            int u = c - 'a';
            if(!p->son[u])  return false;
            p = p->son[u];
        }
        return true;
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
 int main(){
     Trie* obj = new Trie();
     obj->insert("apple");
     bool param_2 = obj->search("apple");
     bool param_3 = obj->startsWith("app");
     cout<<param_2<<endl;
     cout<<param_3<<endl;
     return 0;

 }