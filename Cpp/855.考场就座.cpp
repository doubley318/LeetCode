/*
 * @lc app=leetcode.cn id=855 lang=cpp
 *
 * [855] 考场就座
 */

// @lc code=start
class ExamRoom
{
    vector<int> s;
    int N;
    bool nobody;

public:
    ExamRoom(int n)
    {
        s = vector<int>(n, 0);
        N = n;
        nobody = true;
    }

    int seat()
    {
        if (nobody)
        {
            nobody = false;
            for (int i = 1; i < N; i++)
            {
                s[i] = i;
            }
            return 0;
        }
        int tmp = 0, location = 0;
        for (int i = 0; i < N; i++)
        {
            if ((tmp + 1) / 2 < (s[i] + 1) / 2)
            {
                tmp = s[i];
                location = i;
            }
        }
        if ((location == N - 1) || (s[N - 1] - 1 > (tmp - 1) / 2))
        {
            s[location] = 0;
            return location;
        }
        else if(s[0]==1)
        else
        {
            int t = 0;
            for (int i = location - tmp / 2; i < N && s[i] != 0; i++)
            {
                s[i] = t;
                t++;
            }
            return location - tmp / 2;
        }
    }

    void leave(int p)
    {
        if (p == 0)
        {
            s[0] = 1;
            int i = 1;
            for (; i < N && s[i] != 0; i++)
            {
                s[i] = i + 1;
            }
            if (i == N + 1)
                nobody = true;
            return;
        }
        else
        {
            int t = s[p - 1] + 1;
            s[p] = t;
            for (int i = p; i < N && s[i] != 0; i++, t++)
            {
                s[i] = t;
            }
            return;
        }
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
// @lc code=end
