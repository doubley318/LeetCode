#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> nums(n, 0);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sort(nums.begin(), nums.end());
    for (int i = 0; i < m; i++)
    {
        pq.push(nums[i]);
    }
    for (int i = m; i < n; i++)
    {
        int tmp = pq.top();
        pq.pop();
        pq.push(tmp + nums[i]);
    }
    while (pq.size() != 1)
        pq.pop();
    cout << pq.top();
    return 0;
}