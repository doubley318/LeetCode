/*
 * @lc app=leetcode.cn id=765 lang=cpp
 *
 * [765] 情侣牵手
 */

// @lc code=start
class Solution {
public:
    int minSwapsCouples(vector<int>& row)
    {
        int n = row.size();
        // 记录小组对应的映射
        vector<int> coupleMap(n, 0);
        for (int i = 0; i < n; i += 2) {
            coupleMap[row[i]] = row[i + 1];
            coupleMap[row[i + 1]] = row[i];
        }
        // 找出队友的序号
        auto findCouple = [](int x) -> int {
            if (x % 2 == 0) {
                return x + 1;
            }
            return x - 1;
        };
        // 有没有被访问过
        vector<int> visited(n, 0);
        int ret = 0;
        // 找环
        for (int i = 0; i < n; i += 2) {
            int tmp = i, record = 0;
            while (visited[tmp] == 0) {
                int cp = findCouple(tmp);
                visited[cp] = 1;
                visited[tmp] = 1;
                tmp = coupleMap[cp];
                record += 2;
            }
            if (record != 0) {
                ret += record / 2 - 1;
            }
        }
        return ret;
    }
};
// @lc code=end
