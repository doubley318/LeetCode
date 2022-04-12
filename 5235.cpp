#include "mylib.h"

class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        map<int, vector<int>> mumber;
        vector<vector<int>> ans(2, vector<int>(0));
        for (int i = 0; i < matches.size(); i++)
        {
            if (mumber.find(matches[i][0]) == mumber.end())
                mumber.insert(pair<int, vector<int>>(matches[i][0], {1, 0}));
            else
                mumber.find(matches[i][0])->second[0]++;
            if (mumber.find(matches[i][1]) == mumber.end())
                mumber.insert(pair<int, vector<int>>(matches[i][1], {0, 1}));
            else
                mumber.find(matches[i][1])->second[1]++;
        }
        for (auto i : mumber)
        {
            if (i.second[1] == 0)
                ans[0].push_back(i.first);
            if (i.second[1] == 1)
                ans[1].push_back(i.first);
        }
        return ans;
    }
};

int main()
{
    Solution so;
    vector<vector<int>> matches = {{1, 3}, {2, 3}, {3, 6}, {5, 6}, {5, 7}, {4, 5}, {4, 8}, {4, 9}, {10, 4}, {10, 9}};
    vector<vector<int>> ans = so.findWinners(matches);
    for (int i = 0; i < ans[0].size(); i++)
        cout << ans[0][i] << ",";
    cout << endl;
    for (int i = 0; i < ans[1].size(); i++)
        cout << ans[1][i] << ",";
    return 0;
}