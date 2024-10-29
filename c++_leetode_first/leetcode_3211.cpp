//
// Created by 11818 on 2024/10/29.
//
#include <iostream>
#include <string>
#include <vector>
#include <functional>
using  namespace  std;
class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string > res;
        string str;
        function<void(string&)> dfs = [&](string& str){
            if(str.size() == n){
                res.push_back(str);
                return;
            }
            if(str.empty() || str.back() == '1'){
                str.push_back('0');
                dfs(str);
                str.pop_back();
            }
            str.push_back('1');
            dfs(str);
            str.pop_back();
        };
        dfs(str);
        return res;
    }
};//这个题目就需要保证0身边必须有1进行围着，就是有1的时候才可以加上0才能保证任意两个连续的都有一个1
int main(){
    Solution s;
    int n = 3;
    vector<string> res = s.validStrings(n);
    for(auto st : res){
        cout<<st<<" ";
    }
    cout<<endl;
    return 0;
}