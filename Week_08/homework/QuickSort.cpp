#include <vector>

using namespace std;

int partition(vector<int> &nums, int begin, int end) {
    int pivot = end, counter = begin;

    for (int i = 0; i < end; i++) {
        if (nums[i] < nums[pivot]) {
            swap(nums[i], nums[counter]);
            counter++;
        }
    }

    swap(nums[counter], nums[pivot]);

    return counter;
}

void quickSort(vector<int> &nums, int begin, int end) {
    if (begin > end) return;

    int pivot = partition(nums, begin, end);
    quickSort(nums, begin, pivot - 1);
    quickSort(nums, pivot + 1, end);
}
