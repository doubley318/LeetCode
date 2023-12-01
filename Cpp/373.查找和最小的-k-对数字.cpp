/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的 K 对数字
 */

// @lc code=start
class Solution
{
public:
    struct cmp
    {
        bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
        {
            return a.first > b.first;
        }
    };

    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> pq;
        for (int i = 0; i < nums1.size(); i++)
        {
            pq.push(make_pair(nums1[i] + nums2[0], make_pair(i, 0)));
        }
        vector<vector<int>> res;
        while (!pq.empty() && k--)
        {
            auto tmp = pq.top();
            pq.pop();
            res.push_back({nums1[tmp.second.first], nums2[tmp.second.second]});
            if (tmp.second.second + 1 < nums2.size())
            {
                pq.push(make_pair(nums1[tmp.second.first] + nums2[tmp.second.second + 1], make_pair(tmp.second.first, tmp.second.second + 1)));
            }
        }
        return res;
    }
};
// @lc code=end
