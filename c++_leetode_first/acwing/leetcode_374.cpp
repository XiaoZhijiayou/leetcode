//
// Created by 11818 on 2024/12/6.
//
/**
 * 374.猜数字的大小
 * 我们正在玩猜数字游戏。猜数字游戏的规则如下：
 * 我会从 1 到 n 随机选择一个数字。 请你猜选出的是哪个数字。
 * 如果你猜错了，我会告诉你，我选出的数字比你猜测的数字大了还是小了。
 * 你可以通过调用一个预先定义好的接口 int guess(int num) 来获取猜测结果，返回值一共有三种可能的情况：
 * 1.-1：你猜的数字比我选出的数字大 （即 num > pick）
 * 2.1：你猜的数字比我选出的数字小 （即 num < pick）。
 * 3.0：你猜的数字与我选出的数字相等。（即 num == pick）。
 * 返回我选出的数字。
 * */

#include <iostream>
using namespace std;

class Solution {
public:
    int pick;
    int guess(int a) {
        pick = 6;
        if (a < pick) {
            return 1;
        } else if (a > pick) {
            return -1;
        }
        return 0;
    }
    int guessNumber(int n) {
        int l = 1, r = n;
        while (l < r) {
            int mid = (long long) l + r >> 1;
            if (guess(mid) <= 0) r = mid;
            else
                l = mid + 1;
        }
        return r;
    }
};

int main() {
    int n = 10;
    Solution s;
    cout << s.guessNumber(n);
    return 0;
}