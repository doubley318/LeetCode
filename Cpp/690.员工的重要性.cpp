/*
 * @lc app=leetcode.cn id=690 lang=cpp
 *
 * [690] 员工的重要性
 */

// @lc code=start
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution
{
public:
    Employee *find(const vector<Employee *> &employees, int id)
    {
        for (auto &i : employees)
        {
            if (i->id == id)
            {
                return i;
            }
        }
        return employees[0];
    }

    int getImportance(vector<Employee *> employees, int id)
    {
        queue<Employee *> my_que;
        int res = 0;
        my_que.push(find(employees, id));
        while (!my_que.empty())
        {
            int tmp_size = my_que.size();
            for (int i = 0; i < tmp_size; i++)
            {
                for (auto &j : my_que.front()->subordinates)
                {
                    my_que.push(find(employees, j));
                }
                res += my_que.front()->importance;
                my_que.pop();
            }
        }
        return res;
    }
};
// @lc code=end
