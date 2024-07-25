/*
1. 两数之和
    简单/相关标签/相关企业
|   提示
|   给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
|   你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
|   你可以按任意顺序返回答案。
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // int* plist = (int*)malloc(2 * sizeof(int));
    // *returnSize = 2;

    int* plist = (int*)malloc(*returnSize * sizeof(int));

    for(int i=0; i < numsSize; i ++) {
        for (int j=i+1; j< numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                plist[0] = i;
                plist[1] = j;
            }
        }
    }
    return plist;
}

int main() {
    // int nums[] = {-1, -2, -3, -4, -5};
    // int target = -8;

    // int nums[] = {0,4,3,0};
    // int target = 0;

    int nums[] = { 3, 2, 3 };
    int target = 6;

    int size = sizeof(nums)/sizeof(nums[0]);

    int *returnSize = 2;

    int *result = twoSum(nums, size, target, &returnSize);

    printf("\nResult: %d, %d\n", result[0], result[1]);

    return 0;
}