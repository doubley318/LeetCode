/*
 * @lc app=leetcode.cn id=907 lang=cpp
 *
 * [907] 子数组的最小值之和
 */

// @lc code=start
class Solution
{
    const int MOD = 1e9 + 7;

public:
    int sumSubarrayMins(vector<int> &arr)
    {
        long ans = 0L;
        arr.push_back(-1);
        stack<int> st;
        st.push(-1); // 哨兵
        for (int r = 0; r < arr.size(); ++r)
        {
            while (st.size() > 1 && arr[st.top()] >= arr[r])
            {
                int i = st.top();
                st.pop();
                ans += (long)arr[i] * (i - st.top()) * (r - i); // 累加贡献
            }
            st.push(r);
        }
        return ans % MOD;
    }
};

// @lc code=end
