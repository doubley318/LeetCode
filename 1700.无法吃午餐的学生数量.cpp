/*
 * @lc app=leetcode.cn id=1700 lang=cpp
 *
 * [1700] 无法吃午餐的学生数量
 */

// @lc code=start
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        int stu0 = 0, stu1 = 0;
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i] == 0)
                stu0++;
            else
                stu1++;
        }
        for (int i = 0; i < sandwiches.size(); i++)
        {
            if (sandwiches[i] == 0)
                if (stu0 > 0)
                    stu0--;
                else
                    break;
            else if (stu1 > 0)
                stu1--;
            else
                break;
        }
        return stu0 + stu1;
    }
};
// @lc code=end

