#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> intStack;
        intStack.push(-1);
        int maxArea = 0;
        
        for (int i = 0; i < heights.size(); i++) {
            while(intStack.top() != -1 && heights[i] < heights[intStack.top()]) {
                int k = intStack.top();
                intStack.pop();
                maxArea = max(maxArea, heights[k] * (i - intStack.top() -1));
            }
                
            intStack.push(i);
        } 

        while(intStack.top() != -1) {
            int k = intStack.top();
            intStack.pop();
            maxArea = max(maxArea, heights[k] * ((int)heights.size() - intStack.top() -1));
        }

        return maxArea;
    }
};
