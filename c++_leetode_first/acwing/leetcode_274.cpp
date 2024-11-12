//
// Created by 11818 on 2024/11/12.
//
#include <iostream>
#include <algorithm>
#include <vector>
using  namespace  std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end(),greater<int>());
        //将其按照从大到小排列就可以了
        //然后只需要寻找最后的那个看它是否满足大于等于下标
        for(int i = citations.size(); i >= 1; i--){
            if(citations[i - 1] >= i)
                return i;
        }
        return 0;
    }
};
int main(){
    Solution s;
    vector<int> citations = {3,0,6,1,5};
    cout << s.hIndex(citations) << endl;
    return 0;
}