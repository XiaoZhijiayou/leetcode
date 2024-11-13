//
// Created by 11818 on 2024/11/12.
//

//现在这个基于274，这里面是已经拍好序列的数组
//只不过是从小到大的排序
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int hIndex(vector<int> &citations) {
        int result = citations.size();
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= result) {
                return result;
            } else {
                result--;
            }
        }
        return 0;
    }
};
int main() {
    Solution s;
    vector<int> citations = {0, 1, 3, 5, 6};
    cout << s.hIndex(citations) << endl;
    return 0;
}