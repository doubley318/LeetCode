/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution
{
public:
    struct cmp
    {
        bool operator()(long long a, long long b)
        {
            return a > b;
        }
    };

    int nthUglyNumber(int n)
    {
        priority_queue<long long, vector<long long>, cmp> tmp;
        tmp.push(1);
        set<long long> s;
        s.insert(1);
        long long ret;
        while (n > 0)
        {
            ret = tmp.top();
            tmp.pop();
            if (s.find(ret * 2) == s.end())
            {
                tmp.push(ret * 2);
                s.insert(ret * 2);
            }
            if (s.find(ret * 3) == s.end())
            {
                tmp.push(ret * 3);
                s.insert(ret * 3);
            }
            if (s.find(ret * 5) == s.end())
            {
                tmp.push(ret * 5);
                s.insert(ret * 5);
            }
            n--;
        }
        return (int)ret;
    }
};
// @lc code=end
