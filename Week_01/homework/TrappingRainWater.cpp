#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int area = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!s.empty() && height[i] > height[s.top()]) {
                int lastTop = s.top();
                s.pop();
                if (s.empty())
                    break;
                int wide = i - s.top() - 1;
                int high = min(height[i], height[s.top()]) - height[lastTop];
                area += wide * high;
            }
            s.push(i);
        }
        return area;
    }
};