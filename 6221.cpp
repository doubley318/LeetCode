#include "mylib.h"

class Solution
{
public:
    vector<vector<string>> mostPopularCreator(vector<string> &creators, vector<string> &ids, vector<int> &views)
    {
        // 先把每个创作者的流行度算出来
        // 同时保存每个创作者最高的视频
        unordered_map<string, long long> sum_views;
        unordered_map<string, pair<string, int>> each_views;
        unordered_map<string, long long>::iterator itsum;
        unordered_map<string, pair<string, int>>::iterator iteach;
        vector<vector<string>> ret;
        for (int i = 0; i < creators.size(); i++)
        {
            itsum = sum_views.find(creators[i]);
            iteach = each_views.find(creators[i]);
            if (itsum == sum_views.end())
            {
                sum_views[creators[i]] = views[i];
                each_views[creators[i]] = {ids[i], views[i]};
            }
            else
            {
                itsum->second += views[i];
                if (iteach->second.second < views[i])
                    iteach->second = {ids[i], views[i]};
                else if (iteach->second.second == views[i])
                {
                    if (iteach->second.first > ids[i])
                        iteach->second = {ids[i], views[i]};
                }
            }
        }
        long long tmp = 0;
        for (itsum = sum_views.begin(); itsum != sum_views.end(); itsum++)
        {
            if (tmp < itsum->second)
                tmp = itsum->second;
        }
        for (itsum = sum_views.begin(); itsum != sum_views.end(); itsum++)
        {
            if (itsum->second == tmp)
            {
                ret.push_back({itsum->first, each_views[itsum->first].first});
            }
        }
        return ret;
    }
};