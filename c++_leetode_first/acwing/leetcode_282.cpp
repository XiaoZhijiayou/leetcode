//
// Created by 11818 on 2024/11/12.
//
#include <iostream>
#include <string>
#include <vector>
using namespace  std;
typedef long long LL;
class Solution {
public:
    vector<string> ans;
    string path;

    vector<string> addOperators(string num, int target) {
        path.resize(100);
        dfs(num,0,0,0,1,target);
        return ans;
    }

    void dfs(string& num,int u, int len, LL a,LL b,LL target){
        //1.num就是对应的原始的数
        //2.u就是对应的遍历到第几位数了
        //3.len就是path当时的长度
        //4.a+b * _??? 其中_???这一部分就是对应你加的那一部分
        if(u == num.size()){
            if(a == target) ans.push_back(path.substr(0,len - 1));//为何要-1就是因为为了把+号去掉
        }else {
            LL c = 0;
            for(int i = u; i < num.size();i++){
                c = c * 10 + num[i] - '0';
                path[len++] = num[i];
                //这里面对应上加法部分
                path[len] = '+';
                dfs(num,i + 1,len + 1,a + b * c, 1, target);
                if(i + 1 < num.size()){
                    // -
                    path[len] = '-';
                    dfs(num,i+1,len+1,a + b * c, -1, target);
                    //*
                    path[len] = '*';
                    dfs(num,i + 1,len + 1, a, b * c,target);
                }
                if(num[u] == '0') break;
            }
        }
    }
};

int main(){
    Solution s;
    string num  = "123";
    int target = 6;
    vector<string> result = s.addOperators(num,target);
    for(auto c : result){
        cout << c << " ";
    }
    cout << endl;
    return 0;
}