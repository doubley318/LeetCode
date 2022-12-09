/*
 * @lc app=leetcode.cn id=331 lang=cpp
 *
 * [331] 验证二叉树的前序序列化
 */

// @lc code=start
class Solution
{
public:
    bool isValidSerialization(string preorder)
    {
        int degree_in = 0, degree_out = 1;
        int i = 0;
        for (; i < preorder.size() && degree_in != degree_out; i++)
        {
            if (preorder[i] == '#')
            {
                degree_in++;
                i++;
            }
            else if (preorder[i] == ',')
            {
                degree_in += 1;
                degree_out += 2;
            }
        }
        return (degree_in == degree_out) & (i >= preorder.size());
    }
};
// @lc code=end
