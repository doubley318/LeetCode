/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        set<int> pool;
        while (n != 1)
        {
            if (pool.find(n) != pool.end())
                return false;
            pool.insert(n);
            string tmp = to_string(n);
            n = 0;
            for (int i = 0; i < tmp.length(); i++)
                n += pow((tmp[i] - '0'), 2);
        }
        return true;
    }
};
// @lc code=end

