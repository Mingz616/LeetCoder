/*
* 704. 二分查找
* 简单/相关标签/相关企业
* |给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
*/
#include <stdio.h>

int search(int* nums, int numsSize, int target) {
    // binary search: Ordered & no repetitve number
    // define the left and right index
    int left = 0;
    int right = numsSize - 1;
    // find the middle value and compare with target
    while (left <= right) {
        int middle = left + (right - left) / 2;
        // if middle > target, right = middle - 1
        if (nums[middle] > target) {
            right = middle - 1;
        }
        // if middle < target, left = middle + 1
        else if (nums[middle] < target) {
            left = middle + 1;
        }
        // if middle = target, middle is the result
        else if (nums[middle] == target) {
            return middle;
        }
    }
    return -1;
}

int main() {
    int l1[] = {-1, 0, 3, 5, 9, 12};
    int len = sizeof(l1) / sizeof(int);
    int target = 9;

    int ans = search(l1, len, target);
    printf("Middle: %d", ans);

    return 0;
}