/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
#include <string.h>

#include <string>
using namespace std;

class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        char a[26];
        bzero(a, sizeof(a));

        for (int i = 0; i < s.size(); i++) {
            a[s[i] - 'a']++;
            a[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (a[i] != 0) return false;
        }

        return true;
    }
};
// @lc code=end
