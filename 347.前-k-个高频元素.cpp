/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    struct cmp {
        bool operator()(const pair<int, int>& x, const pair<int, int>& y)
        {
            return x.first > y.first;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> myMap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> myPQ;
        for (auto& i : nums) {
            myMap[i]++;
        }
        for (auto& i : myMap) {
            myPQ.push(make_pair(i.second, i.first));
            if (myPQ.size() > k) {
                myPQ.pop();
            }
        }
        vector<int> res(k);
        for (int i = 0; i < k; i++) {
            res[i] = myPQ.top().second;
            myPQ.pop();
        }
        return res;
    }
};
// @lc code=end
