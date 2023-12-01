/*
 * @lc app=leetcode.cn id=1054 lang=cpp
 *
 * [1054] 距离相等的条形码
 */

// @lc code=start
class Solution
{
public:
    vector<int> rearrangeBarcodes(vector<int> &barcodes)
    {
        map<int, int> my_map;
        for (int &i : barcodes)
        {
            my_map[i]++;
        }
        vector<pair<int, int>> tmp;
        for (auto i : my_map)
        {
            tmp.push_back({i.second, i.first});
        }
        sort(tmp.begin(), tmp.end(), [](pair<int, int> &a, pair<int, int> &b)
             { return (a.first > b.first); });
        int n = barcodes.size();
        vector<int> res(n, 0);
        int t = 0;
        for (int i = 0; i < tmp.size(); i++)
        {
            while (tmp[i].first)
            {
                tmp[i].first--;
                res[t] = tmp[i].second;
                t += 2;
                if (t >= n)
                    t = 1;
            }
        }
        return res;
    }
};
// @lc code=end
