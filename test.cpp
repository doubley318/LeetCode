#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>
void test(int **p6)
{
    int *x = (int *)malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++)
        x[i] = i;
    for (int i = 0; i < 10; i++)
    {
        *p6 = x;
    }
}

int main()
{
    int **str = (int **)malloc(sizeof(int *) * 10);
    for (int i = 0; i < 10; i++)
    {
        str[i] = (int *)malloc(sizeof(int) * 10);
    }
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            str[i][j] = i * 10 + j;
    printf("Before:\n");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d\t", str[i][j]);
        }
        printf("\n");
    }
    test(str);
    printf("After:\n");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d\t", str[i][j]);
        }
        printf("\n");
    }

    return 0;
}
