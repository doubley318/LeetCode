/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 */

// @lc code=start
class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if (numerator == 0)
            return "0";
        string ret;
        long numera = numerator, denomin = denominator;
        if (numerator < 0 && denominator > 0)
        {
            ret = "-";
            numera = -numera;
        }
        else if (numerator > 0 && denominator < 0)
        {
            ret = "-";
            denomin = -denomin;
        }
        else if (numerator < 0 && denominator < 0)
        {
            numera = -numera;
            denomin = -denomin;
        }
        string numer = to_string(numera);
        int point = 0;
        long beichushu = 0;
        int tmp_res = 0;
        unordered_map<long, int> memoray;
        unordered_map<long, int>::iterator it;
        while (beichushu < denomin && point != numer.size())
        {
            beichushu = beichushu * 10 + numer[point] - '0';
            point++;
        }
        if (beichushu >= denomin)
        {
            tmp_res = beichushu / denomin;
            beichushu = beichushu % denomin;
            ret = ret + to_string(tmp_res);
        }
        while (point != numer.size())
        {
            if (beichushu < denomin)
            {
                beichushu = beichushu * 10 + numer[point] - '0';
                point++;
                while (beichushu < denomin && point != numer.size())
                {
                    beichushu = beichushu * 10 + numer[point] - '0';
                    point++;
                    ret = ret + "0";
                }
            }
            if (beichushu == 0)
            {
                return ret + "0";
            }
            if (beichushu >= denomin)
            {
                tmp_res = beichushu / denomin;
                beichushu = beichushu % denomin;
                ret = ret + to_string(tmp_res);
            }
        }
        if (tmp_res == 0)
            ret = ret + "0";
        if (beichushu != 0)
            ret = ret + ".";
        while (beichushu != 0)
        {
            if (beichushu < denomin)
            {
                beichushu = beichushu * 10;
                while (beichushu < denomin)
                {
                    beichushu = beichushu * 10;
                    ret = ret + "0";
                }
            }
            if (beichushu >= denomin)
            {
                it = memoray.find(beichushu);
                if (it == memoray.end())
                {
                    memoray.insert({beichushu, ret.size()});
                    tmp_res = beichushu / denomin;
                    beichushu = beichushu % denomin;
                    ret = ret + to_string(tmp_res);
                }
                else
                {
                    ret.insert(it->second, "(");
                    ret = ret + ")";
                    return ret;
                }
            }
        }
        return ret;
    }
};
// @lc code=end
