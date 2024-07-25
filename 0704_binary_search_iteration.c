#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    binarySearch(nums, 0, numsSize - 1, target);    // initialize the edge of left & right
}

int binarySearch(int* nums, int left, int right, int target) {
    if (left > right) return -1;                        // outage edge
    int middle = left + (right - left) / 2;             // define the middle
    if (nums[middle] == target) {                       // exit: middle is the target
        return middle;
    }
    if (nums[middle] > target) {                        // target in the left range
        binarySearch(nums, left, middle - 1, target);       // iteration with updated left & right
    }
    else if (nums[middle] < target) {                   // target in the right range
        binarySearch(nums, middle + 1, right, target);      // iteration with updated left & right
    }
}

int main() {
    int l1[] = {-1, 0, 3, 5, 9, 12};
    int len = sizeof(l1) / sizeof(int);
    int target = 9;

    int ans = search(l1, len, target);
    printf("Middle: %d", ans);

    return 0;
}