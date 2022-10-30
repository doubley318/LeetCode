#include <stdio.h>
int main()
{
    int i = 0, n, s = 0, x = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        int a[i];
        scanf("%d\n", &a[i]);
        s = a[i];
        x = 0;
        if (a[i] < 10)
        {
            printf("Yes\n");
        }
        else
        {
            while (s > 0)
            {
                x = x * 10 + s % 10;
                s = s / 10;
            }
            if (x == a[i])
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
    }
    return 0;
}