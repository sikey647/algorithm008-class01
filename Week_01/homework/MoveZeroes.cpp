#include <vector>
using namespace std;

// 解法一
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i])
                swap(nums[i], nums[index++]);
        }
    }
};

// 解法二
class Solution2 {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                if (nums[i] != nums[index]) {
                    nums[index] = nums[i];
                    nums[i] = 0;
                }
                index++;
            }
        }
    }
};