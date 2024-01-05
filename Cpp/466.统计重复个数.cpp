/*
 * @lc app=leetcode.cn id=466 lang=cpp
 *
 * [466] 统计重复个数
 */

// @lc code=start
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2)
    {
        // 直接找最小公倍数
        int l1 = s1.length(), l2 = s2.length();
        int c1 = 0, c2 = 0, p1 = 0, p2 = 0;
        do {
            if (s1[p1] == s2[p2]) {
                p2++;
            }
            p1++;
            if (p1 == l1) {
                c1++;
                p1 = 0;
            }
            if (p2 == l2) {
                c2++;
                p2 = 0;
            }
        } while (!(p1 == 0 && p2 == 0));
        return (int)((double)n1 * c2 / n2 / c1);
    }
};
// @lc code=end
