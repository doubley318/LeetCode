/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
class Solution {
public:
    vector<int> diffWaysToCompute(string expression)
    {
        vector<int> res, vec1, vec2;
        int n = expression.size();
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
            {
                flag = 1;
                vec1 = diffWaysToCompute(expression.substr(0, i));
                vec2 = diffWaysToCompute(expression.substr(i + 1, n - i - 1));
                for (int j = 0; j < vec1.size(); j++)
                {
                    for (int k = 0; k < vec2.size(); k++)
                    {
                        if (expression[i] == '+')
                            res.push_back(vec1[j] + vec2[k]);
                        else if (expression[i] == '-')
                            res.push_back(vec1[j] - vec2[k]);
                        else
                            res.push_back(vec1[j] * vec2[k]);
                    }
                }
            }
        }
        if (flag == 0)
            res.push_back(stoi(expression));
        return res;
    }
};
// @lc code=end

