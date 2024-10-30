//
// Created by 11818 on 2024/7/25.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int n = sequence.size();
        if (n == 0) return false;
        return dfs(sequence, 0, n - 1);
    }
    bool dfs(vector<int> &sequence, int left, int right) {
        if (left >= right) return true;

        int root = sequence[right];

        //开始划分区间

        int j = right - 1;

        while (j >= 0 && sequence[j] > root) j--;

        //检查左子树是不是存在大于根节点的数
        for (int i = left; i <= j; i++) {
            if (sequence[i] > root) return false;
        }

        //然后对左右子树分别进行判断
        return dfs(sequence, left, j) && dfs(sequence, j + 1, right - 1);
    }
};

int main() {
    Solution s;
    vector<int> sequence = {5, 7, 6, 9, 11, 10, 8};
    bool res = s.VerifySquenceOfBST(sequence);
    cout << res << endl;
    return 0;
}