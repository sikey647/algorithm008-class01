#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> sub;
        _combine(0, k, 1, n, sub, res);
        return res;
    }

    void _combine(int level, int k, int start, int n, vector<int>& sub,
                  vector<vector<int>>& res) {
        if (level == k) {
            res.push_back(sub);
            return;
        }

        for (int i = start; i <= n; i++) {
            sub.push_back(i);
            _combine(level + 1, k, i + 1, n, sub, res);
            sub.pop_back();
        }
    }
};