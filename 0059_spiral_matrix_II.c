/*
* 59. 螺旋矩阵 II
* 中等/相关标签/相关企业
* 给你一个正整数 n ，生成一个包含 1 到 square(n) 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = n;                                    //行数
    *returnColumnSizes = (int*)malloc(sizeof(int));     
    returnColumnSizes = &returnSize;                    //列数

    // printf("%d\t", *returnSize);   
    // printf("%d\n", **returnColumnSizes);   
    
    /******************************************************** 
    // 创建一个 n*n 的二维数组，下面的方法不适合返回二级指针，因为创建的二维数组和函数的返回类型不一致。
    // 1. 声明一个指针变量，用来保存每一行数据的指针,也就是列数据地址,即 n=列的值
    int (*matrix)[n];
    // 2. 分配内存，也就定义了行数据的指针。此时 n=行的值
    matrix = (int (*)[n])malloc(n * sizeof(int[0]));

    // 验证使用：二级指针下存放着3个地址指针，
    // int len = sizeof(*matrix) / sizeof(int);
    // printf("%d\r\n", len);
    // printf("%p\r\n", matrix[0]);
    // printf("%p\r\n", matrix[1]);
    // printf("%p\r\n", matrix[2]);
    ******************************************************** */

    // 或者,用函数传进来的参数进行创建这个二维数组。
    int **matrix;   // 二级指针
    matrix = (int**)malloc( (*returnSize) * sizeof(int*) );             //分配行指针数组
    for (int i = 0; i < *returnSize; i++) {
        matrix[i] = (int*)malloc( (**returnColumnSizes) * sizeof(int) );//分配每一行的列 
    }


    // 开始解算
    int loop = n / 2;       //圈数
    int middle = n / 2;     //中间值的坐标参考点
    int coord_x = 0;        //初值坐标参考点
    int coord_y = 0;
    int x, y;               
    int offset = 1;         //为了让每一个区间（ ]右闭环，每循环一圈，增加 1
    int val = 1; 

    while (loop--) {
        x = coord_x;
        y = coord_y;

        for (y; y < n - offset; y++) {
           matrix[x][y] = val++;
        //    printf("(%d,%d):\t%d\n", x,y,matrix[x][y]);
        }
        for (x; x < n - offset; x++) {
            matrix[x][y] = val++;
            // printf("(%d,%d):\t%d\n", x,y,matrix[x][y]);
        }
        for (y; y > coord_y; y--) {
            matrix[x][y] = val++;
            // printf("(%d,%d):\t%d\n", x,y,matrix[x][y]);
        }
        for (x; x > coord_x; x--) {
            matrix[x][y] = val++;
            // printf("(%d,%d):\t%d\n", x,y,matrix[x][y]);
        }

        coord_x++;
        coord_y++;
        
        offset++;
    }

    if (n%2) {
        matrix[middle][middle] = val;
        // printf("(%d,%d):\t%d\n", middle,middle,matrix[middle][middle]);
    }

    return matrix;
}

int main() {
    // int n = 3;
    // int n = 5;
    int n = 4;

    int returnSize;
    int *returnColumnSizes;
    int **matrix;

    matrix = generateMatrix(n, &returnSize, &returnColumnSizes);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("(%d,%d): %d\t", i,j, matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}