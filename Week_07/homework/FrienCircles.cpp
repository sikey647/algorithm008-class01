/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 朋友圈
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
   public:
    int findCircleNum(vector<vector<int> >& M) {
        if (M.empty()) return 0;

        int n = M.size();
        vector<int> parents(n);
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }

        int count = n;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (M[i][j]) {
                    int parent1 = find(i, parents);
                    int parent2 = find(j, parents);
                    if (parent1 != parent2) {
                        parents[parent1] = parent2;
                        count--;
                    }
                }
            }
        }

        return count;
    }

    int find(int x, vector<int>& parents) {
        // if (x == parents[x])
        //     return x;
        // else
        //     return find(parents[x], parents);
        return parents[x] == x ? x : find(parents[x], parents);
    }
};
// @lc code=end
