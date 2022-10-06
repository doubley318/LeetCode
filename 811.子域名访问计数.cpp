/*
 * @lc app=leetcode.cn id=811 lang=cpp
 *
 * [811] 子域名访问计数
 */

// @lc code=start
class Solution
{
public:
    vector<string> subdomainVisits(vector<string> &cpdomains)
    {
        unordered_map<string, int> record;
        unordered_map<string, int>::iterator it;
        for (int i = 0; i < cpdomains.size(); i++)
        {
            int firstspace = cpdomains[i].find(" ");
            int times = stoi(cpdomains[i].substr(0, firstspace));
            string domain = cpdomains[i].substr(firstspace + 1);
            it = record.find(domain);
            if (it == record.end())
                record.insert({domain, times});
            else
                it->second = it->second + times;
            firstspace = domain.find(".");
            while (firstspace != -1)
            {
                domain = domain.substr(firstspace + 1);
                it = record.find(domain);
                if (it == record.end())
                    record.insert({domain, times});
                else
                    it->second = it->second + times;
                firstspace = domain.find(".");
            }
        }
        vector<string> ret;
        while (!record.empty())
        {
            it = record.begin();
            ret.push_back(to_string(it->second) + " " + it->first);
            record.erase(it);
        }
        return ret;
    }
};
// @lc code=end
