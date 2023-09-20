#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct cmp1 {
    bool operator()(int x, int y)
    {
        return x < y;
    }
};

struct cmp2 {
    bool operator()(int x, int y)
    {
        return x > y;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        priority_queue<int, vector<int>, cmp1> Big;
        priority_queue<int, vector<int>, cmp2> Small;
        vector<int> nums(n, 0);
        long long tmp_res = 0;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            Big.push(nums[i]);
            Small.push(nums[i]);
            tmp_res += nums[i];
        }
        if ((tmp_res + n - 1) / n > r || (tmp_res) / n < l) {
            cout << "-1" << endl;
            continue;
        }
        long long res = 0;
        while (Small.top() < l && Big.top() > r) {
            int b = Big.top();
            int s = Small.top();
            Big.pop();
            Small.pop();
            int d = min(l - s, b - r);
            res += d;
            s += d;
            b -= d;
            Small.push(s);
            Big.push(b);
        }
        if (Small.top() >= l && Big.top() <= r) {
            cout << res << endl;
        } else if (Small.top() >= l) {
            while (Big.top() > r) {
                res += Big.top() - r;
                Big.pop();
            }
            cout << res << endl;
        } else {
            while (Small.top() < l) {
                res += l - Small.top();
                Small.pop();
            }
            cout << res << endl;
        }
    }
    return 0;
}