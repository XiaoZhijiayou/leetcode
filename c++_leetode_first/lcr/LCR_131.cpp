//
// Created by 11818 on 2024/11/7.
//
#include <iostream>
#include <vector>
using namespace  std;
class Solution {
public:
    int cuttingBamboo(int bamboo_len) {
        vector<int> f(bamboo_len + 1);
        f[0] = 0;
        f[1] = 1;
        for(int i = 2; i <= bamboo_len; i++){
            for(int j = 1; j < i; j++){
                f[i] = max({f[i],f[i - j] * j,(i - j)*j});
            }
        }
        return f[bamboo_len];
    }
};
//f[i] 就是 i能够分割出来的最大乘积
//f[i]分为三种情况
//1.f[i]最大
//2.f[i - j]*j
//3.（i-j） * j
int main(){
    int bamboo_len = 12;
    Solution s;
    cout<<s.cuttingBamboo(bamboo_len)<<endl;
    return 0;
}