/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        int l = version1.find('.');
        int r = version2.find('.');
        int a, b;
        while (l != string::npos && r != string::npos)
        {
            a = stoi(version1.substr(0, l));
            b = stoi(version2.substr(0, r));
            if (a < b)
                return -1;
            else if (a > b)
                return 1;
            version1 = version1.substr(l + 1, version1.size());
            version2 = version2.substr(r + 1, version2.size());
            l = version1.find('.');
            r = version2.find('.');
        }
        if (l == string::npos && r == string::npos)
        {
            a = stoi(version1);
            b = stoi(version2);
        }
        else if (l == string::npos)
        {
            a = stoi(version1);
            b = stoi(version2.substr(0, r));
            if (a == b)
            {
                version2 = version2.substr(r + 1, version2.size());
                r = version2.find('.');
                while (r != string::npos)
                {
                    b = stoi(version2.substr(0, r));
                    if (b != 0)
                        return -1;
                    version2 = version2.substr(r + 1, version2.size());
                    r = version2.find('.');
                }
                b = stoi(version2);
                if (b != 0)
                    return -1;
                return 0;
            }
        }
        else
        {
            a = stoi(version1.substr(0, l));
            b = stoi(version2);
            if (a == b)
            {
                version1 = version1.substr(l + 1, version1.size());
                l = version1.find('.');
                while (l != string::npos)
                {
                    a = stoi(version1.substr(0, l));
                    if (a != 0)
                        return 1;
                    version1 = version1.substr(l + 1, version1.size());
                    l = version1.find('.');
                }
                a = stoi(version1);
                if (a != 0)
                    return 1;
                return 0;
            }
        }
        if (a < b)
            return -1;
        else if (a > b)
            return 1;
        else
            return 0;
    }
};
// @lc code=end
