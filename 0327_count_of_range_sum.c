/*
* 327. 区间和的个数
* 困难/相关标签/相关企业
* 给你一个整数数组 nums 以及两个整数 lower 和 upper 。求数组中，值位于范围 [lower, upper] （包含 lower 和 upper）之内的 区间和的个数 。
* 区间和 S(i, j) 表示在 nums 中，位置从 i 到 j 的元素之和，包含 i 和 j (i ≤ j)。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int countRangeSum(int* nums, int numsSize, int lower, int upper) {
    int* sum = (int*)malloc(sizeof(int) * numsSize);
    memset(sum, 0, sizeof(sum));

    int ans = 0;

    int index_low = 0;
    int index_high = INT32_MAX;

    for (int i = 0; i < numsSize; i++) {
        if (i == 0) {
            sum[0] = nums[0];
            if (sum[0] >= lower && sum[0] <= upper) {
                index_low = 0;
                printf("%d:\t%d\n", i, sum[i]);
            }
        }
        else {
            sum[i] = sum[i-1] + nums[i];
            if (sum[i] >= lower && sum[i] <= upper) {
                index_high = i;
                printf("%d:\t%d\n", i, sum[i]);
            }
        }
        
        if (index_high > numsSize && index_low > numsSize) {
            ans = 0;
            printf("%d:\t%d\n", i, ans);
        }
        else {
            ans += 1;
            printf("%d:\t%d\n", i, ans);
        }
    }
    return ans;
}

int main() {
    int l1[] = {-2,5,-1};
    int lower = -2;
    int upper = 2;

    // int l1[] = {0};
    // int lower = 0;
    // int upper = 0;

    int len = sizeof(l1) / sizeof(int);
    printf("%d\r\n", len);

    int ans = countRangeSum(l1, len, lower, upper);
    printf("%d\r\n", ans);

    return 0;
}