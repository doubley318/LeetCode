/*
 * @lc app=leetcode.cn id=823 lang=cpp
 *
 * [823] 带因子的二叉树
 */

// @lc code=start
class Solution {
public:
#define ll long long
#define M 1000000007

    int numFactoredBinaryTrees(vector<int>& arr)
    {
        unordered_map<ll, ll> mymap;
        sort(arr.begin(), arr.end());
        mymap[arr[0]]++;
        ll res = 1;
        for (int i = 1; i < arr.size(); i++) {
            ll tmp = 1, l = 0, r = i - 1;
            while (l <= r) {
                ll res = (ll)arr[l] * arr[r];
                if (res > arr[i]) {
                    r--;
                } else if (res < arr[i]) {
                    l++;
                } else {
                    if (l == r) {
                        tmp = (mymap[arr[l]] * mymap[arr[r]] + tmp) % M;
                    } else {
                        tmp = (mymap[arr[l]] * mymap[arr[r]] * 2 + tmp) % M;
                    }
                    l++;
                    r--;
                }
            }
            res = (tmp + res) % M;
            mymap[arr[i]] = tmp;
        }
        return (int)res;
    }
};
// @lc code=end
