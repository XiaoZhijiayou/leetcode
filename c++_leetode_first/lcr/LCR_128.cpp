//
// Created by 11818 on 2024/11/3.
//
//LCR128.库存管理|

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int inventoryManagement(vector<int> &stock) {
        int left = 0, right = stock.size() - 1;
        while (left < right) {
            int middle = (left + right) >> 1;
            if (stock[middle] < stock[right]) {
                //这个说明middle一定在右排序当中
                right = middle;
            } else if (stock[middle] > stock[right]) {
                //这个说明middle一定在左排序当中
                left = middle + 1;
            } else {
                //这时候他们相等的时候,就是开始缩小范围
                right--;
            }
        }
        return stock[left];
    }
};

int main() {
    Solution s;
    vector<int> stock = {4, 5, 8, 3, 4};
    cout << s.inventoryManagement(stock) << endl;
    return 0;
}