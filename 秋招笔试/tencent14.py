T=int(input())
for i in range(0,T):
    n=int(input())
    k=int(input())
    if (n==k):
        print(0)
    else:
        print((1<<(n-k))%1000000007)
