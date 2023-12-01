/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数

int main()
{
    Solution so;
    // 379
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {1,2,3};
    cout << so.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
 */

// @lc code=start
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        double res;
        int lenth1 = -1;
        int lenth2 = -1;
        int lenthsum = (nums1.size() + nums2.size()) / 2 + (nums1.size() + nums2.size()) % 2;
        int ptr1 = 0;
        int ptr2 = 0;
        while (lenthsum > 1 && ptr1 < nums1.size() && ptr2 < nums2.size())
        {
            ptr1 = lenthsum / 2 + lenth1;
            ptr2 = lenthsum / 2 + lenth2;
            if (ptr1 >= nums1.size())
                ptr1 = nums1.size() - 1;
            if (ptr2 >= nums2.size())
                ptr2 = nums2.size() - 1;
            if (nums1[ptr1] < nums2[ptr2])
            {
                lenthsum = lenthsum - ptr1 + lenth1;
                lenth1 = ptr1;
                ptr1++;
            }
            else
            {
                lenthsum = lenthsum - ptr2 + lenth2;
                lenth2 = ptr2;
                ptr2++;
            }
            // lenthsum = lenthsum - lenthsum / 2;
        }
        if (ptr1 >= nums1.size())
        {
            // ptr2 = ptr2 + lenthsum - 1;
            int tmp = (nums1.size() + nums2.size()) / 2 - nums1.size();
            if ((nums1.size() + nums2.size()) % 2 == 1)
                return nums2[tmp];
            return (nums2[tmp] + nums2[tmp - 1]) * 0.5;
        }
        else if (ptr2 >= nums2.size())
        {
            // ptr1 = ptr1 + lenthsum - 1;
            int tmp = (nums1.size() + nums2.size()) / 2 - nums2.size();
            if ((nums1.size() + nums2.size()) % 2 == 1)
                return nums1[tmp];
            return (nums1[tmp] + nums1[tmp - 1]) * 0.5;
        }
        else
        {
            if ((nums1.size() + nums2.size()) % 2 == 1)
                return nums1[ptr1] < nums2[ptr2] ? nums1[ptr1] : nums2[ptr2];
            else
            {
                if (ptr1 + 1 < nums1.size())
                {
                    if (nums1[ptr1 + 1] < nums2[ptr2])
                        return (nums1[ptr1] + nums1[ptr1 + 1]) * 0.5;
                }
                if (ptr2 + 1 < nums2.size())
                {
                    if (nums2[ptr2 + 1] < nums1[ptr1])
                        return (nums2[ptr2] + nums2[ptr2 + 1]) * 0.5;
                }
                return (nums1[ptr1] + nums2[ptr2]) * 0.5;
            }
        }
    }
};
// @lc code=end
