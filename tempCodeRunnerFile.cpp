int isPrime(int n)
{
    if (n <= 0)
        return 0;
    for (int i = 2; i < n / 2; i++)
    {
        if (n % i == 0)
            return 0;
        if (i == n / 2 - 1)
            return 1;
    }
    return 0;
}

int decompose(int n)
{
    int flag = 0;
    for (int i = 2; i <= n / 2; i++)
    {
        if (isPrime(i) && isPrime(n - i))
        {
            printf("%d=%d+%d\n", n, i, n - i);
            flag = 1;
        }
    }
    return flag;
}