/*
 * @lc app=leetcode.cn id=689 lang=cpp
 *
 * [689] 三个无重叠子数组的最大和
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k)
    {
        // 算出每k个值的和
        int n = nums.size();
        int N = n - k + 1;
        vector<int> Sum(N, 0);
        int presum = 0, tmpsum = 0;
        for (int i = 0; i < k; i++) {
            tmpsum += nums[i];
        }
        for (int i = k; i <= n; i++) {
            Sum[i - k] = tmpsum - presum;
            if (i < n) {
                tmpsum += nums[i];
                presum += nums[i - k];
            }
        }
        // 求出Sum[i]左边最大数的索引和右边最大数的索引（包含自己）
        vector<int> LeftSum(N, 0);
        vector<int> RightSum(N, 0);
        int LeftMax = 0, RightMax = 0;
        int LeftIdx = 0, RightIdx = N - 1;
        for (int i = 0; i < N; i++) {
            if (LeftMax < Sum[i]) {
                LeftIdx = i;
                LeftMax = Sum[i];
            }
            if (RightMax <= Sum[N - i - 1]) {
                RightIdx = N - i - 1;
                RightMax = Sum[N - i - 1];
            }
            LeftSum[i] = LeftIdx;
            RightSum[N - i - 1] = RightIdx;
        }
        // 选择中间的点，从第k个开始到N-k-1个结束
        int sumMax = 0;
        vector<int> ret(3, 0);
        for (int i = k; i < N - k; i++) {
            int tmp = Sum[i] + Sum[LeftSum[i - k]] + Sum[RightSum[i + k]];
            if (tmp > sumMax) {
                ret[0] = LeftSum[i - k];
                ret[1] = i;
                ret[2] = RightSum[i + k];
                sumMax = tmp;
            }
        }
        return ret;
    }
};
// @lc code=end
