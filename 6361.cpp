#include "mylib.h"

class Solution
{
public:
    // struct cmp
    // {
    //     bool operator()(int a, int b)
    //     {
    //         return a > b;
    //     }
    // };

    int minimizeSum(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 3)
            return 0;
        // 最大的三个数
        priority_queue<int, vector<int>, greater<int>> pq;
        // 最小的三个数
        priority_queue<int, vector<int>, less<int>> pq2;
        for (int i = 0; i < n; i++)
        {
            if (pq.size() < 3)
                pq.push(nums[i]);
            else
                pq.push(nums[i]), pq.pop();
            if (pq2.size() < 3)
                pq2.push(nums[i]);
            else
                pq2.push(nums[i]), pq2.pop();
        }
        int max3 = pq2.top();
        pq2.pop();
        int max2 = pq2.top();
        pq2.pop();
        int max1 = pq2.top();
        int min3 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();
        int min1 = pq.top();
        printf("%d %d %d\n", max1, max2, max3);
        printf("%d %d %d\n", min1, min2, min3);

        int a = abs(max1 - min3);
        int b = abs(max2 - min2);
        int c = abs(max3 - min1);
        return min(a, min(b, c));
    }
};

int main()
{
    Solution so;
    vector<int> nums = {58, 42, 8, 75, 28};
    cout << so.minimizeSum(nums);
    return 0;
}