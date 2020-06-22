/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    // 状态数组：f[i]为字符串从0到i个字符中解码方法总数。
    // DP方程：
    // s[i] == 0 :
    //  s[i-1]s[i] <= 26: (两者为整体，不可拆分; s[i-1] == 1 or s[i-1] == 2):
    //      f[i] = f[i-2]
    // s[i] != 0 :
    //  s[i-1]s[i] <= 26: (两者可拆，也可为整体; s[i-1] == 1 or s[i-1] == 2,
    //  s[i] <= 6)
    //      f[i] = f[i-1] + f[i-2]
    //  s[i-1]s[i] > 26: (两者必拆; s[i-1] == 2 and s[i] > 6)
    //      f[i] = f[i-1]
    int numDecodings(string s) {
        if (s[0] == '0') return 0;

        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '0') {
                if (s[i - 1] == '1' or s[i - 1] == '2') {
                    dp[i + 1] = dp[i - 1];
                }
            } else {
                if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                    dp[i + 1] = dp[i] + dp[i - 1];
                } else {
                    dp[i + 1] = dp[i];
                }
            }
        }

        return dp[s.size()];
    }
};
// @lc code=end
