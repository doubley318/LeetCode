/*
 * @lc app=leetcode.cn id=2276 lang=cpp
 *
 * [2276] 统计区间中的整数数目
 */

// @lc code=start
class CountIntervals {
    map<int, int> mp;
    int cnt = 0;

public:
    CountIntervals()
    {
    }

    void add(int left, int right)
    {
        auto l = mp.upper_bound(right);
        while (!mp.empty() && l != mp.begin() && (*(--l)).second >= left) {
            cnt -= ((*l).second - (*l).first + 1);
            left = min((*l).first, left);
            right = max((*l).second, right);
            mp.erase(l);
            l = mp.upper_bound(right);
        }
        mp.insert({ left, right });
        cnt += right - left + 1;
    }

    int count()
    {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
// @lc code=end
