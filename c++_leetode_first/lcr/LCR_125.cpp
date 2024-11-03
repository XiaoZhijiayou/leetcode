//
// Created by 11818 on 2024/10/31.
//
#include <iostream>
#include <stack>
using namespace std;
class CQueue {
public:
    //这个题目就是实现一个队列的形式，先进先出
    //利用两个栈来实现
    CQueue() {
    }

    void appendTail(int value) {
        st1.push(value);
    }

    int deleteHead() {
        //这里面利用上st1用来存储保存过的值
        //将保存的值都弹到st2里面
        //弹出全部之后，就取出来st2的头部
        //这里面处理完上面之后st1可以为空，也可以不为空，
        //因为如果st2为空的话，会直接从st1里面取元素直接弹入到st1里面
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        if (st2.empty())
            return -1;
        int result = st2.top();
        st2.pop();
        return result;
    }

private:
    stack<int> st1, st2;
};

int main() {
    CQueue *myQueue = new CQueue();
    myQueue->appendTail(1);
    myQueue->appendTail(2);
    cout << myQueue->deleteHead() << endl;
    return 0;
}