//
// Created by 11818 on 2024/12/26.
//

/**
 * leetcode_28:找出字符串中第一个匹配项的下标
 * 给你两个字符串 haystack 和 needle ，
 * 请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
 * 如果 needle 不是 haystack 的一部分，则返回  -1 。
 *
 *
 * 方法：kmp算法
 * next数组：对应的就是前缀表
 *  前缀表就是：
 *      1.一个数组中以第一个字母开头的相互构成的字串和以数组尾部的最后一个字符加上前面的连续字串构成的后缀
 *      2.当这个前后缀相同的时候，就是当前前缀表的大小
 *  next[i]就是i之前最长相等的前后缀的长度
 *  next[0] = -1;
 *
 *  next数组的命名分配主要有三个过程
 *      1. 先将next[0] = -1;先进行赋值
 *      2. 然后i 与 j i代表后缀的尾部， j+1代表前缀的尾部，这时候就需要对s[j+1] 与 s[i]进行判断
 *      3. 首先s[j+1] == s[i]时，将 j前进，然后将next[i] = j;
 *      4. 其次s[j+1] != s[i]时，将 j跳转到next[j]，直到发现他们相等为止才算跳转结束。
 *
 *      这里面为何一直时候j+1进行判断，可以保证如果不相等的话直接传入nextj就可以了，不需要再回退
 *      并且开始的时候j就是为-1
 *
 *
 *  输入：haystack = "sadbutsad", needle = "sad"
 *  输出： 0
 * */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    void getNext(int *next, const string &s) {
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); i++) {
            while (j >= 0 && s[i] != s[j + 1]) {
                j = next[j];///向前回退
            }
            if (s[i] == s[j + 1]) {///找到相同的前后缀
                j++;
            }
            next[i] = j;/// 将 j前缀的长度赋给next[i]
        }
    }
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        vector<int> next(needle.size());
        getNext(&next[0], needle);
        int j = -1;
        for (int i = 0; i < haystack.size(); i++) {
            while (j >= 0 && haystack[i] != needle[j + 1]) {
                j = next[j];
            }
            if (haystack[i] == needle[j + 1]) {
                j++;
            }
            if (j == (needle.size() - 1)) {
                return (i - needle.size() + 1);///可以理解为haystack取到i，然后对应的将i - needle.size() + 1
            }
        }
        return -1;
    }
};

int main() {
    string haystack = "sadbutsad";
    string needle = "sad";
    Solution s;
    cout << s.strStr(haystack, needle) << endl;
    return 0;
}