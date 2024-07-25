/*
* 977. 有序数组的平方
* 简单/相关标签/相关企业
* 给你一个按 非递减顺序 排序的整数数组 nums，
* 返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// O(n + n * log(n)): bubble sort
int* sortedSquares1(int* nums, int numsSize, int* returnSize) {
    // reversal the vector and square each of value
    for (int i = 0; i < numsSize; i++) {
        nums[i] *= nums[i];
    }
    // bubble sort: from small to large
    int tmp;
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] > nums[j]) {
                tmp = nums[j];
                nums[j] = nums[i];
                nums[i] = tmp;
            }
        }
    }
    *returnSize = numsSize;
    return nums;
}

// O(n): double pointer 有序序列平方后，极值只能出现在两侧，因为有可能有负数
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int *new = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    
    // two pointers on both edges
    int left = 0;                       // left = 0
    int right = numsSize - 1;           // right = 5 - 1 = 4
    int index = numsSize - 1;           // index = 5 - 1 = 4
    for(left, right; left <= right; ) {
        // square(left) > square(right): left++
        if (nums[left] * nums[left] > nums[right] * nums[right]) {
            new[index--] = nums[left] * nums[left];
            left++;
        }
        // square(right) > square(left): right--
        else {
            new[index--] = nums[right] * nums[right];
            right--;
        }
    }

    return new;
}

// calculate the function's time spent
double statisticalTimeCost(int (*func)) {
    clock_t begin = clock();            // start
    *func;
    // while(clock() < begin + 5000);   // delay 5s manually
    clock_t end = clock();              // end
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC / 1000; // millisecond
    return time_spent;
}

int main() {
    int l1[] = {-4,-1,0,3,10};
    // int l1[] = {-7,-3,2,3,11};

    int len = sizeof(l1) / sizeof(int);

    int *length = (int*)malloc(sizeof(int));
    int *ans = (int*)malloc(sizeof(int) * len);

    ans = sortedSquares(l1, len, length);
    
    for (int i = 0; i < *length; i++) {
        printf("%d\t", ans[i]);
    }

    // statistical the algorithm's time spent
    double time_spent = statisticalTimeCost(sortedSquares);
    printf("\n%lf ms", time_spent);

    return 0;
}