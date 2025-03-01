#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        vector<vector<string>> res;
        for (auto str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            map[key].push_back(str);
        }
        for (auto pair : map) {
            res.push_back(pair.second);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = s.groupAnagrams(strs);
    for (auto vec : res) {
        for (auto str : vec) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}