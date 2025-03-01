//
// Created by 11818 on 2024/12/1.
//
/**
 * 352.将数据流变成多个不相交的区间
 * 1.找到左端点 <= x的最后一个区间
 * 2.如果x不在区间内部
 *      1. x-1 x x+1
 *      2. x-1 x
 *      3.     x x+1
 *      4.     [x,x]
 * */
#include <iostream>
#include <set>
#include <vector>
#include <climits>
using namespace std;
typedef long long LL;
const LL INF = 1e18;
typedef pair<LL, LL> PLL;
#define x first;
#define y second;
class SummaryRanges {
public:
    set<PLL> s;//set 内部都会确保元素始终按照升序排列。
    SummaryRanges() {
        s.insert({-INF, -INF});
        s.insert({INF, INF});
    }

    void addNum(int value) {
        //1.情况一：区间包含了这个value值
        auto r = s.upper_bound({value, INT_MAX});//这个比较的方式就是先比较第一个参数进行比较，然后才会去比较第二个，所以只要第一个严格大于就可以了
        auto l = r;
        l--;
        if (l->second >= value) return;
        /**第二种情况：不包含这一点，但是有他对应的左和右区间部分*/
        if (l->second == value - 1 && r->first == value + 1) {
            s.insert({l->first, r->second});
            s.erase(l);
            s.erase(r);
        } else if (l->second == value - 1 && r->first != value + 1) {
            s.insert({l->first, value});
            s.erase(l);
        } else if (l->second != value - 1 && r->first == value + 1) {
            s.insert({value, r->second});
            s.erase(r);
        } else {
            s.insert({value, value});
        }
        return;
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto &p: s) {
            if (p.first != -INF && p.second != INF) {
                res.push_back(vector<int>{(int) p.first, (int) p.second});
            }
        }
        return res;
    }
};

void print_vec(const vector<vector<int>> &a_vec) {
    cout << '[';
    for (auto c: a_vec) {
        cout << '[';
        for (auto a: c) {
            cout << a << ',';
        }
        cout << ']' << ",";
    }
    cout << ']' << endl;
}

int main() {
    SummaryRanges *obj = new SummaryRanges();
    obj->addNum(1);
    print_vec(obj->getIntervals());
    obj->addNum(3);
    obj->addNum(7);
    obj->addNum(2);
    obj->addNum(6);
    print_vec(obj->getIntervals());
}