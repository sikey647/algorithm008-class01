/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
#include <string>
#include <algorithm>
using namespace std;

// 解法一：sort + compare
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

// 解法二：hash
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
            
        int c[26];
        bzero(c, sizeof(c));
        for (int i = 0; i < s.size(); i++) {
            c[s[i] - 'a']++;
            c[t[i] - 'a']--;
        }
        
        for (int j = 0; j < 26; j++) {
            if (c[j] != 0)
                return false;
        }

        return true;
    }
};

// Accepted
// 34/34 cases passed (4 ms)
// Your runtime beats 99.77 % of cpp submissions
// Your memory usage beats 100 % of cpp submissions (7.5 MB)



// @lc code=end

