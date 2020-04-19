#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ret;
    int size = nums.size();
    if (size < 3)
        return ret;
    
    sort(nums.begin(), nums.end());
    
    // 如果最大的数小于0，那么任意三数之和不为0
    if (nums[size-1] < 0)
        return ret;
    
    for (int i = 0; i < size - 2; i++) {
        if (nums[i] > 0)
            break;
        if (i > 0 && nums[i] == nums[i-1])
            continue;
        int left = i + 1, right = nums.size() - 1;
        while(left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum > 0) {
                while (left < right && nums[right] == nums[--right]);
            } else if (sum < 0) {
                while (left < right && nums[left] == nums[++left]);
            } else {
                ret.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[++left]);
                while (left < right && nums[right] == nums[--right]);
            }
        }
    }
    return ret;
}