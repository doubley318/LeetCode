#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int myLowerBound(const vector<int>& nums, double x)
{
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (nums[m] >= x) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return l;
}

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
{
    sort(potions.begin(), potions.end());
    int n = spells.size(), m = potions.size();
    vector<int> ret(n, 0);
    for (int i = 0; i < n; i++) {
        ret[i] = m - myLowerBound(potions, (double)success / spells[i]);
    }
    return ret;
}

int main()
{
    vector<int> spells = { 5, 1, 3 };
    vector<int> potions = { 1, 2, 3, 4, 5 };
    long long success = 7;
    successfulPairs(spells, potions, success);
    return 0;
}