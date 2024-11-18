//
// Created by 11818 on 2024/11/18.
//
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
int main() {
    string beginStr, endStr, str;
    int n;
    cin >> n;
    unordered_set<string> strset;
    cin >> beginStr >> endStr;
    for (int i = 0; i < n; i++) {
        cin >> str;
        strset.insert(str);
    }
    //记录strSet中的字符串是否被访问过，同时记录路径长度
    unordered_map<string, int> visitMap;

    //初始化队列
    queue<string> que;
    que.push(beginStr);

    visitMap.insert(pair<string, int>{beginStr, 1});
    while (!que.empty()) {
        string word = que.front();
        que.pop();
        int path = visitMap[word];//字符串中的路径的长度
        for (int i = 0; i < word.size(); i++) {
            string newWord = word;
            //遍历26位字母
            for (int j = 0; j < 26; j++) {
                newWord[i] = j + 'a';
                if (newWord == endStr) {
                    cout << path + 1 << endl;
                    return 0;
                }
                //字符串集合中出现了newWord，并且newWord没有被访问
                if (strset.find(newWord) != strset.end() && visitMap.find(newWord) == visitMap.end()) {
                    //添加访问信息，并将新的字符串放到队列之中
                    visitMap.insert({newWord, path + 1});
                    que.push(newWord);
                }
            }
        }
    }
    cout << 0 << endl;
    return 0;
}

//int main() {
//    string beginStr, endStr, str;
//    int n;
//    cin >> n;
//    unordered_set<string> strset;
//
//    cin >> beginStr >> endStr;
//
//    for (int i = 0; i < n; i++) {
//        cin >> str;
//        strset.insert(str);
//    }
//
//    unordered_map<string, int> strmap;
//    strmap.insert({beginStr, 1});
//    queue<string> que;
//    que.push(beginStr);
//    while (!que.empty()) {
//        auto word = que.front();
//        que.pop();
//        int path = strmap[word];
//
//        for (int i = 0; i < word.size(); i++) {
//            auto newWord = word;
//            for (int j = 0; j < 26; j++) {
//                newWord[i] = j + 'a';
//                if (newWord == endStr) {
//                    cout << path + 1 << endl;
//                    return 0;
//                }
//                if (strset.find(newWord) != strset.end() &&
//                    strmap.find(newWord) == strmap.end()) {
//                    strmap.insert({newWord, path + 1});
//                    que.push(newWord);
//                }
//            }
//        }
//    }
//    cout << 0 << endl;
//    return 0;
//}