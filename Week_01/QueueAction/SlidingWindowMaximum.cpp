#include <vector>
#include <queue>
using namespace std;

class MonotonousQueue {
private:
    deque<int> de;

public:
    void push(int v) {
        while(!de.empty() && v > de.back())
            de.pop_back();
        de.push_back(v);
    }

    void pop(int v) {
        if (!de.empty() && de.front() == v)
            de.pop_front();
    }

    int max() {
        return de.front();
    }
}; 

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonousQueue window;
        vector<int> ret;

        for (int i = 0; i < nums.size(); i++) {
            if(i < k - 1) {
                window.push(nums[i]);
            } else {
                window.push(nums[i]);
                ret.push_back(window.max());
                window.pop(nums[i-(k-1)]);
            }
        }

        return ret;
    }
};
