/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */

// @lc code=start
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int arr[10];
        bzero(arr, sizeof(arr));

        int ACnt = 0, BCnt = 0, NCnt = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                ACnt++;
            } else {
                arr[secret[i] - '0']++;
                arr[guess[i] - '0']--;
            }
        }

        for (int i = 0; i < 10; i++) {
            if (arr[i] > 0)
                NCnt += arr[i];
        }
        BCnt = secret.size() - ACnt - NCnt;
        return to_string(ACnt) + "A" + to_string(BCnt) + "B";

    }
};

// Accepted
// 152/152 cases passed (4 ms)
// Your runtime beats 95.54 % of cpp submissions
// Your memory usage beats 100 % of cpp submissions (6.6 MB)
// @lc code=end

