//
// Created by 11818 on 2024/12/19.
//

/**
 * 58.区间和
 * 给定一个整数数组 Array，请计算该数组在每个指定区间内元素的总和。
 *
 * 输入描述：
 *  第一行输入为整数数组 Array 的长度 n，接下来 n 行，每行一个整数，表示数组的元素。随后的输入为需要计算总和的区间下标：a，b （b > = a），直至文件结束
 * 输出描述：
 *  输出每个指定区间的元素的总和
 *
 *  这里面需要引入前缀和的思路：
 *      前缀和的思想是重复计算过的子数组的和，从而降低区间查询需要累加的次数。
 *      就是计算从0到i之间的数组之和
 *      5
        1
        2
        3
        4
        5
        0 1
        1 3

        3
        9
 * */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, a, b;
    cin >> n;
    vector<int> vec(n);
    vector<int> p(n);
    int presum = 0;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        presum += vec[i];
        p[i] = presum;
    }
    while (cin >> a >> b) {
        int sum;
        if (a == 0) sum = p[b];
        else
            sum = p[b] - p[a - 1];
        cout << sum << endl;
    }
    return 0;
}
