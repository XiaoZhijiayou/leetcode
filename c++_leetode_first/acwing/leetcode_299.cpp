//
// Created by 11818 on 2024/11/14.
//

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> hash;
        for (auto c: guess) hash[c]++;
        int count = 0;
        for (auto ch: secret) {
            if (hash[ch]) {
                count++;
                hash[ch]--;
            }
        }

        int bulls = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i])
                bulls++;
        }

        return to_string(bulls) + "A" + to_string(count - bulls) + "B";
    }
};

int main() {
    string secret = "1807", guess = "7810";

    Solution s;
    cout << s.getHint(secret, guess) << endl;
    return 0;
}