/*
 * @lc app=leetcode.cn id=2383 lang=cpp
 *
 * [2383] 赢得比赛需要的最少训练时长
 */

// @lc code=start
class Solution
{
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int> &energy, vector<int> &experience)
    {
        int n = energy.size();
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (initialExperience <= experience[i])
            {
                res += experience[i] - initialExperience + 1;
                initialExperience = 2 * experience[i] + 1;
            }
            else
                initialExperience += experience[i];
            if (initialEnergy <= energy[i])
            {
                res += energy[i] - initialEnergy + 1;
                initialEnergy = 1;
            }
            else
                initialEnergy -= energy[i];
        }
        return res;
    }
};
// @lc code=end
