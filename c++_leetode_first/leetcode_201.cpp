//
// Created by 11818 on 2024/10/24.
//
#include <iostream>
using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res = 0;
        for (int i = 30; i >= 0; i--) {
            if ((left >> i & 1) != (right >> i & 1)) break;
            if (left >> i & 1) res += 1 << i;//这个就相当于把前面相等的位都加起来，后面遇到不相等部分的话，直接等于零了
        }
        return res;
    }
};
//思路部分：
//1.首先，先找出来最高位部分相同的数字，然后把他们相同部分的存起来在result中，
//2.对于不相同部分，因为 n >= xxxx100000的 对应上m <= xxxx011111.
//3.你所有中间的数都是要和这两个数相与的这两数相与肯定对应位数全部为零，对应的对于第一个高位不相等部分可以直接等于零就可以了
int main() {
    Solution s;
    int left = 5;
    int right = 7;
    cout << s.rangeBitwiseAnd(left, right) << endl;
    return 0;
}