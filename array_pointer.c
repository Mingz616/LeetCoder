#include <stdio.h>

int main()
{
    int a[2][3] = {1, 2, 3, 4, 5, 6};
    // printf("%d***%d", *(a[1]+1), (*a+1)[1]);
    int len = sizeof(a) / sizeof(int);
    
    printf("%d\t%d\r\n", *(a[1] + 1), (*a+1)[1]);
    return 0;
}