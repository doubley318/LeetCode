#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &nums[i]);
    }
    int M;
    cin >> M;
    vector<int> left(M);
    vector<int> right(M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &left[i]);
    }
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &right[i]);
    }
    string op;
    cin >> op;
    vector<int> para(M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &para[i]);
    }
    vector<int> my_tmp(N, 0);

    int l, r, p;
    char o;
    for (int i = 0; i < M; i++)
    {
        // left[i]是第i次操作时候的左区间，right是右区间
        // op是第i次操作的操作符，p是操作数。
        l = left[i];
        r = right[i];
        o = op[i];
        p = para[i];
        if (o == '=')
            for (int j = l - 1; j < r; j++)
                my_tmp[j] = i;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = my_tmp[i]; j < M; j++)
        {
            l = left[j];
            r = right[j];
            if (l - 1 > i || i >= r)
                continue;
            o = op[j];
            p = para[j];
            switch (o)
            {
            case '=':
                nums[i] = p;
                break;
            case '|':
                nums[i] |= p;
                break;
            case '&':
                nums[i] &= p;
                break;
            }
        }
        cout << nums[i] << " ";
    }
    return 0;
}