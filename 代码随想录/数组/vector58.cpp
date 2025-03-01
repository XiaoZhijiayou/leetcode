#include <iostream>
#include <vector>
using namespace std;

// 暴力搜索的做法做不了，需要存储前缀和
// 前缀和的做法

int count_sum (vector<int> &nums, int a, int b) {
    int sum = 0;
    for (int i = a; i <= b; i++) {
        sum += nums[i];
    }
    return sum;
}


int main() {
    int length = 0;
    cin >> length;
    vector<int> nums(length);
    for (int i = 0; i < length; i++) {
        cin >> nums[i];
    }
    vector<int> prefix_sum(length + 1, 0);
    for (int i = 1; i <= length; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + nums[i - 1];
    }
    int a = 0, b = 0;
    while (cin >> a >> b) {
        cout << prefix_sum[b + 1] - prefix_sum[a] << endl;
    }
    return 0;
}