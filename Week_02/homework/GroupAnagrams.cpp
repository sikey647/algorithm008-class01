/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// sort + hash
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> vecMap;
        for (auto &str : strs) {
            auto s = str; 
            sort(s.begin(), s.end());
            auto itr = vecMap.find(s);
            if (itr != vecMap.end())
                itr->second.push_back(str);
            else
                vecMap[s] = vector<string>{str};
        }
        for (auto &elem : vecMap)
            res.push_back(elem.second);
        return res;
    }
};
// @lc code=end

