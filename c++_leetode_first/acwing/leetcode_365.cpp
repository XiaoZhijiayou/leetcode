//
// Created by 11818 on 2024/12/5.
//

//365.水壶问题
/**
 * 有两个水壶，容量分别为 x 和 y 升。水的供应是无限的。确定是否有可能使用这两个壶准确得到 target 升。
 *
 * 你可以：
    装满任意一个水壶
    清空任意一个水壶
    将水从一个水壶倒入另一个水壶，直到接水壶已满，或倒水壶已空。
        两个被子不可能同时既不空也不满
 * */

#include <iostream>
using namespace std;
class Solution {
public:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
    bool canMeasureWater(int a, int b, int c) {
        if (c > a + b) return false;
        return !c || c % gcd(a, b) == 0;//一种是c为零时候是成立的，一种是c能够被ab的最大公约数相除以
    }
};
/**
 * 1.首先这两个水壶不能同时装满，所以这个c > a + b
 * 2.其次分情况
 *          B大于A的情况下
 *          1.B装满  A为空 -> 2.B倒入A  使得A装满 -> 3. A清空 B还有剩余 -> 4.B倒入A中，使得B空 -> 5.使得B装满 ，且A半满的情况 -> 6.B倒入A中，确保A装满， B不满
 *          这个情况下当前总水量的变化情况：+-(A)  +-(B) +-(B-A) 一般就这六种情况
 * 3.所以 就是ax + by = c这样的一个方程满足就可以了，它有解对应的就是：求a，b的最大公约数能不能整除c
 * */

 int main() {
    return 0;
 }