//
// Created by 11818 on 2024/11/24.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> countNumbers(int cnt) {
        if (cnt <= 0) return vector<int>(0);
        vector<int> res;
        int num = 1;
        for (int i = 0; i < cnt; ++i)
            num *= 10;// 比如 n=3，num就是1000
        for (int i = 1; i < num; ++i) res.push_back(i);
        return res;
    }
};
