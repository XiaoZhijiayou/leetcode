//
// Created by 11818 on 2024/12/4.
//
//355.设计推特
/**
 * 1.需要存储两个表：
 *          1.推特列表 user_id -> 推特列表    用hash嵌套vector
 *          2.每个用户关注了哪些用户 user_id  -> 关注列表  hash嵌套hash
 * */
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
class Twitter {
public:
    unordered_map<int, vector<PII>> tweets;
    unordered_map<int, unordered_set<int>> follows;
    int ts;
    Twitter() {
        ts = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({ts, tweetId});
        ts++;
    }
    /**
     * 检索当前用户新闻推送中最近  10 条推文的 ID 。
     * 新闻推送中的每一项都必须是由用户关注的人或者是用户自己发布的推文。推文必须 按照时间顺序由最近到最远排序
     * */
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> heap;
        follows[userId].insert(userId);
        for (auto &user: follows[userId]) {
            auto &ts = tweets[user];
            if (ts.size()) {
                int i = ts.size() - 1;
                heap.push({ts[i].first, ts[i].second, i, user});//这个是获取该用户的最后一条推文，将最后一条推文插入进去
            }
        }
        vector<int> res;
        for (int i = 0; i < 10 && heap.size(); i++) {
            auto t = heap.top();
            heap.pop();
            res.push_back(t[1]);
            int j = t[2];//这个是将该用户的前面的推文都插入进去
            if (j) {
                j--;
                int user = t[3];
                auto &ts = tweets[user];
                heap.push({ts[j].first, ts[j].second, j, user});
            }
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};
void pr(vector<int> &n) {
    for (auto i: n) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    Twitter *obj = new Twitter();
    obj->postTweet(1, 5);
    vector<int> get_1 = obj->getNewsFeed(1);
    pr(get_1);
    obj->follow(1, 2);
    obj->postTweet(2, 6);
    vector<int> get_2 = obj->getNewsFeed(1);
    pr(get_2);
    obj->unfollow(1, 2);
    vector<int> get_3 = obj->getNewsFeed(1);
    pr(get_3);
    return 0;
}