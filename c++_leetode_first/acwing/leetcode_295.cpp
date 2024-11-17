//
// Created by 11818 on 2024/11/14.
//
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
private:
    priority_queue<int> smaller;                          // 最大堆，存储较小的一半数
    priority_queue<int, vector<int>, greater<int>> larger;// 最小堆，存储较大的一半数
public:
    MedianFinder() {}

    void addNum(int num) {
        // 插入到适当的堆中
        if (smaller.empty() || num <= smaller.top()) {
            smaller.push(num);
        } else {
            larger.push(num);
        }

        // 保持两个堆的平衡，使得smaller堆的元素数大于等于larger堆
        if (smaller.size() > larger.size() + 1) {
            int top = smaller.top();
            smaller.pop();
            larger.push(top);
        } else if (larger.size() > smaller.size()) {
            int top = larger.top();
            larger.pop();
            smaller.push(top);
        }
    }

    double findMedian() {
        if ((larger.size() + smaller.size()) % 2 == 0) {// 总数为偶数
            return (larger.top() + smaller.top()) / 2.0;
        } else {// 总数为奇数
            return smaller.top();
        }
    }
};

// 测试实例
int main() {
    MedianFinder mf;

    mf.addNum(1);
    cout << "Median after adding 1: " << mf.findMedian() << endl;

    mf.addNum(2);
    cout << "Median after adding 2: " << mf.findMedian() << endl;

    mf.addNum(3);
    cout << "Median after adding 3: " << mf.findMedian() << endl;

    mf.addNum(4);
    cout << "Median after adding 4: " << mf.findMedian() << endl;

    mf.addNum(5);
    cout << "Median after adding 5: " << mf.findMedian() << endl;

    return 0;
}
