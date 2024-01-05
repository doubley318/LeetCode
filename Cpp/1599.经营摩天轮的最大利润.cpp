/*
 * @lc app=leetcode.cn id=1599 lang=cpp
 *
 * [1599] 经营摩天轮的最大利润
 */

// @lc code=start
class Solution {
public:
    bool check(const vector<int>& mo)
    {
        for (const int& i : mo) {
            if (i != 0) {
                return true;
            }
        }
        return false;
    }

    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost)
    {
        // 模拟？
        int n = customers.size();
        int retTimes = -1;
        int maxIncome = 0, tmpIncome = 0;
        vector<int> mo(4, 0);
        int point = 0;
        int remind = 0;
        for (int i = 0; i < n; i++) {
            remind += customers[i];
            if (remind >= 4) {
                mo[(point) % 4] = 4;
                remind -= 4;
                tmpIncome += boardingCost * 4 - runningCost;
                point++;
            } else if (remind > 0) {
                mo[(point) % 4] = remind;
                tmpIncome += boardingCost * remind - runningCost;
                point++;
                remind = 0;
            } else if (check(mo)) {
                tmpIncome -= runningCost;
                mo[(point) % 4] = 0;
                point++;
            }
            if (tmpIncome > maxIncome) {
                maxIncome = tmpIncome;
                retTimes = point;
            }
        }
        while (remind >= 4) {
            remind -= 4;
            mo[(point) % 4] = 4;
            tmpIncome += boardingCost * 4 - runningCost;
            point++;
            if (tmpIncome > maxIncome) {
                maxIncome = tmpIncome;
                retTimes = point;
            }
        }
        if (remind > 0) {
            tmpIncome += boardingCost * remind - runningCost;
            point++;
            if (tmpIncome > maxIncome) {
                maxIncome = tmpIncome;
                retTimes = point;
            }
        }

        return retTimes;
    }
};
// @lc code=end
