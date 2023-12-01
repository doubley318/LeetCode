/*
 * @lc app=leetcode.cn id=481 lang=cpp
 *
 * [481] 神奇字符串
 */

// @lc code=start
class Solution {
public:
    int magicalString(int n)
    {
        vector<int> tmp = {1, 2, 2};
        int ret = 1;
        if (n <= 3)
            return 1;
        int mark = 2;
        for (int i = 3; i < n;)
        {
            int x = tmp[i - 1];
            int y = tmp[mark];
            x = x == 2 ? 1 : 2;
            i += y;
            if (x == 1)
            {
                if (i <= n)
                    ret += y;
                else
                    ret += 1;
            }
            while (y > 0)
            {
                tmp.push_back(x);
                y--;
            }
            mark++;
        }
        return ret;
    }
};
// @lc code=end

