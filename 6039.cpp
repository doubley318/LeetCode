#include "mylib.h"

class Solution
{
public:
    int maximumProduct(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> num;
        for (int i : nums)
            num.push(i);
        for (int i = 0; i < k; i++)
        {
            int tmp = num.top();
            tmp++;
            num.pop();
            num.push(tmp);
        }
        long long ans = 1;
        while (!num.empty())
        {
            ans = (num.top() * ans) % 1000000007;
            num.pop();
        }
        return (int)ans;
    }
};

int main()
{
    Solution so;

    return 0;
}