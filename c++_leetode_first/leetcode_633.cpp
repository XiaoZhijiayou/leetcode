//
// Created by 11818 on 2024/11/4.
//
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int a = 0; a * a <= c/2; a++){
            int b = sqrt(c - a * a);
            if(a*a + b*b == c){
                return true;
            }
        }
        return false;
    }
};

int main(){
    int c = 5;
    Solution s;
    cout << s.judgeSquareSum(c) << endl;
    return 0;
}