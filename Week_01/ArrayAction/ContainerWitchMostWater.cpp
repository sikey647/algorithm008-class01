#include <vector>
using namespace std;

// 解法一：暴力
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        for (int i = 0; i < height.size() - 1; i++) {
            for (int j = i + 1; j < height.size(); j++) {
                int min_height = height[i] < height[j] ? height[i] : height[j];
                int area = (j - i) * min_height;
                max_area = area > max_area ? area : max_area; 
            }
        }
        return max_area;
    }
};

// 解法二：双指针
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        for (int i = 0, j = height.size() - 1; i < j; ) {
            int min_height = height[i] < height[j] ? height[i++] : height[j--];
            int area = (j - i + 1) * min_height;
            max_area = area > max_area ? area : max_area; 
        }
        return max_area;
    }
};