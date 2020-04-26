/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            priorityQueue;
        unordered_map<int, int> cntMap;

        for (auto num : nums) {
            cntMap[num]++;
        }

        for (auto cnt : cntMap) {
            priorityQueue.push({cnt.second, cnt.first});
            while (priorityQueue.size() > k) {
                priorityQueue.pop();
            }
        }

        vector<int> res;
        while (!priorityQueue.empty()) {
            res.push_back(priorityQueue.top().second);
            priorityQueue.pop();
        }

        return res;
    }
};
// @lc code=end
