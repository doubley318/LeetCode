/*
 * @lc app=leetcode.cn id=927 lang=cpp
 *
 * [927] 三等分
 */

// @lc code=start
class Solution
{
public:
    vector<int> threeEqualParts(vector<int> &arr)
    {
        vector<int> false_ret = {-1, -1};
        int amount_1 = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 1)
                amount_1++;
        }
        if (amount_1 == 0)
            return {0, (int)(arr.size()) - 1};
        if (amount_1 % 3 != 0)
            return false_ret;
        int l = -1, r = -1, tmp = 0, last = -1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 1)
                tmp = tmp + 1;
            if (tmp == amount_1 / 3 && l == -1)
                l = i;
            else if (tmp == (amount_1 / 3) * 2 && r == -1)
                r = i;
            else if (tmp == amount_1 && last == -1)
                last = i;
        }
        int number_0 = arr.size() - last - 1;
        for (int i = 1; i <= number_0; i++)
        {
            if (arr[l + 1] == 0)
                l++;
            else
                return false_ret;
            if (arr[r + 1] == 0)
                r++;
            else
                return false_ret;
        }
        last = arr.size() - 1;
        int each_1 = amount_1 / 3;
        int already_1 = 0;
        for (int i = 0; i < r - l && already_1 < each_1; i++)
        {
            if (arr[l - i] == arr[r - i] && arr[l - i] == arr[last - i])
            {
                if (arr[l - i] == 1)
                    already_1++;
            }
            else
                return false_ret;
        }
        return {l, r + 1};
    }
};
// @lc code=end
