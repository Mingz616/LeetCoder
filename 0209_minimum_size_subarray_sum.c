/*
* 209. 长度最小的子数组
* 中等/相关标签/相关企业
* 给定一个含有 n 个正整数的数组和一个正整数 target 。
* 找出该数组中满足其总和大于等于 target 的长度最小的 子数组
* [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
*/

#include <stdio.h>
#include <stdint.h>

// O(n^2)
int minSubArrayLen1(int target, int* nums, int numsSize) {
    int sum;
    int length = 0;
    int ans = INT32_MAX;
    for (int i = 0; i < numsSize; i++) {
        sum = 0;
        for (int j = i; j < numsSize; j++) {
            sum += nums[j];
            if (sum >= target) {
                length = j - i + 1;
                break;
            }
        }
        ans = ans < length ? ans : length;
    }
    return ans;
}

// O(n): double pointer to acheive sliding window
int minSubArrayLen(int target, int* nums, int numsSize) {
    int sum = 0;
    int length;
    int ans = INT32_MAX;
    int flag = 0;
    int start = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        while (sum >= target) {
            flag = 1;
            length = i - start + 1;
            ans = ans < length ? ans : length;
            sum -= nums[start++];
        }
    }
    if (flag == 0) {
        ans = 0;
    }
    return ans;
}

int main() {
    // int l1[] = {2,3,1,2,4,3};
    // int target = 7;      // ans = 2

    int l1[] = {1,4,4};
    int target = 4;         // ans = 1

    // int l1[] = {1,1,1,1,1,1,1,1};
    // int target = 11;        // ans = 0

    // int l1[] = {5,1,3,5,10,7,4,9,2,8};
    // int target = 15;     // ans = 2

    int len = sizeof(l1) / sizeof(int);

    int ans = minSubArrayLen(target, l1, len);
    printf("%d\n", ans);

    return 0;
}