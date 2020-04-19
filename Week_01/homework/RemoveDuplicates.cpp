#include <vector>
using namespace std;

// 双指针/快慢指针
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();
        int index = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[index])
                nums[++index] = nums[j];
        }
        return index + 1;
    }
};