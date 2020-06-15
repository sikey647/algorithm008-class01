#include <queue>
#include <vector>
using namespace std;

void heapSort(vector<int> &nums) {
    priority_queue<int, vector<int>, greater<int> > q;

    for (int num : nums) {
        q.push(num);
    }

    for (int i = 0; i < nums.size(); i++) {
        nums[i] = q.top();
        q.pop();
    }
}
