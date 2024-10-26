//
// Created by 11818 on 2024/10/24.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
    vector<bool> st(n+1);
    vector<int> primes;
    for(int i=2;i<=n;i++){
        if(!st[i]) primes.push_back(i);
        for(int j=0;j<primes.size() && i*primes[j]<n;j++){
            st[i*primes[j]]=true;//这样是标识当前的是和数，下次就不用再判断了
            if(i%primes[j]==0) break;//筛选时如果遇到 i % primes[j] == 0，表示 i 已经被 primes[j] 这个质数整除，
            // 为了保证线性筛的效率（每个合数只被标记一次），我们停止筛选并退出循环。
        }
    }
    return primes.size();
    }
};
int main() {
    Solution s;
    cout<<s.countPrimes(10)<<endl;
    return 0;
}