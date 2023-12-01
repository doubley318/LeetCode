class Solution
{
public:
    int minnumber(int a, int b, int c)
    {
        a = a < b ? a : b;
        a = a < c ? a : c;
        return a;
    }
    int getKthMagicNumber(int k)
    {
        vector<int> res(k, 1);
        int a = 0, b = 0, c = 0;
        int tmp = 0, number = 1;
        while (k != number)
        {
            tmp = minnumber(res[a] * 3, res[b] * 5, res[c] * 7);
            if (tmp == res[a] * 3)
                a++;
            if (tmp == res[b] * 5)
                b++;
            if (tmp == res[c] * 7)
                c++;
            res[number] = tmp;
            number++;
        }
        return res[number - 1];
    }
};