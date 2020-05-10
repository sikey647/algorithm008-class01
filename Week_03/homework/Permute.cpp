#include <map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        map<int, int> _map;
        for (int& e : nums) _map[e]++;
        _permute(nums.size(), _map, sub, res);
        return res;
    }

    void _permute(int size, map<int, int>& _map, vector<int>& sub,
                  vector<vector<int>>& res) {
        if (sub.size() == size) {
            res.push_back(sub);
            return;
        }

        for (auto& e : _map) {
            if (e.second == 0) continue;
            sub.push_back(e.first);
            e.second--;
            _permute(size, _map, sub, res);
            sub.pop_back();
            e.second++;
        }
    }
};