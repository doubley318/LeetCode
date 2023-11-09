/*
 * @lc app=leetcode.cn id=2258 lang=cpp
 *
 * [2258] 逃离火灾
 */

// @lc code=start
class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid)
    {
        queue<pair<int, int>> queFire;
        queue<pair<int, int>> queMan;
        int m = grid.size(), n = grid[0].size();
        // 火焰步数
        vector<vector<int>> stepFire(m, vector<int>(n, 1e9));
        vector<vector<int>> stepMan(m, vector<int>(n, 1e9));
        // 判断是否出了边界
        auto isVaild = [&m, &n, &grid](int x, int y) -> bool {
            if ((x >= 0 && x <= m - 1) && (y >= 0 && y <= n - 1) && (grid[x][y] != 2)) {
                return true;
            }
            return false;
        };
        // 刷新步数
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    queFire.push({ i, j });
                    stepFire[i][j] = 0;
                }
            }
        }
        stepMan[0][0] = 0;
        // 对step进行操作
        auto opStep = [&isVaild](vector<vector<int>>& step, queue<pair<int, int>>& que, int x, int y, int opx, int opy) -> void {
            if (isVaild(opx, opy) && (step[opx][opy] > step[x][y] + 1)) {
                que.push({ opx, opy });
                step[opx][opy] = step[x][y] + 1;
            }
        };
        // 更新火焰步数
        while (!queFire.empty()) {
            int fireSize = queFire.size();
            for (int i = 0; i < fireSize; i++) {
                int x = queFire.front().first, y = queFire.front().second;
                opStep(stepFire, queFire, x, y, x - 1, y);
                opStep(stepFire, queFire, x, y, x + 1, y);
                opStep(stepFire, queFire, x, y, x, y - 1);
                opStep(stepFire, queFire, x, y, x, y + 1);
                queFire.pop();
            }
        }
        // 火焰到达安全屋的步数
        int stepFire2Room = stepFire[m - 1][n - 1];
        // 更新人的步数
        queMan.push({ 0, 0 });
        while (!queMan.empty()) {
            int manSize = queMan.size();
            for (int i = 0; i < manSize; i++) {
                int x = queMan.front().first, y = queMan.front().second;
                opStep(stepMan, queMan, x, y, x - 1, y);
                opStep(stepMan, queMan, x, y, x + 1, y);
                opStep(stepMan, queMan, x, y, x, y - 1);
                opStep(stepMan, queMan, x, y, x, y + 1);
                queMan.pop();
            }
        }
        stack<pair<int, int>> staRoom2Man;
        staRoom2Man.push({ m - 1, n - 1 });
        // 人到安全屋的步数
        int stepMan2Room = stepMan[m - 1][n - 1];
        // 人到达不了或者步数大于火焰，则失败
        if (stepMan2Room == 1e9 || stepMan2Room > stepFire2Room) {
            return -1;
        } else if (stepFire2Room == 1e9) {
            return 1e9;
        }
        // 判断是否是路径
        auto isFast = [&stepMan, &isVaild, &staRoom2Man, &stepFire](int x, int y, int opx, int opy) -> int {
            if (isVaild(opx, opy) && (stepMan[opx][opy] < stepMan[x][y])) {
                staRoom2Man.push({ opx, opy });
                return stepFire[opx][opy] - stepMan[opx][opy] - 1;
            }
            return 1e9;
        };
        // 从安全屋反向走回去，使用深度优先搜索，因为有多个路径
        int ret = -1, tmpret = 1e9;
        while (!staRoom2Man.empty()) {
            int x = staRoom2Man.top().first, y = staRoom2Man.top().second;
            staRoom2Man.pop();
            tmpret = min(tmpret, isFast(x, y, x - 1, y));
            tmpret = min(tmpret, isFast(x, y, x + 1, y));
            tmpret = min(tmpret, isFast(x, y, x, y - 1));
            tmpret = min(tmpret, isFast(x, y, x, y + 1));
            if (x == 0 && y == 0) {
                ret = max(ret, tmpret);
            }
        }
        if (ret > 0 && stepMan2Room == stepFire2Room) {
            return 0;
        }
        return ret >= 0 ? ret : -1;
    }
};
// @lc code=end
