#include <vector>
using namespace std;

void merge(vector<int> &nums, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right)
        temp[k++] = nums[i] <= nums[j] ? nums[i++] : nums[j++];

    while (i <= mid) temp[k++] = temp[i++];
    while (j <= right) temp[k++] = temp[j++];

    for (int p = 0; p < temp.size(); p++) {
        nums[left + p] = temp[p];
    }
}

void mergeSort(vector<int> &nums, int left, int right) {
    if (left > right) return;

    int mid = (left + right) >> 1;  // (left + right) / 2
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}