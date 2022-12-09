/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int number = image[sr][sc];
        queue<pair<int, int>> que;
        que.push({sr, sc});
        while (!que.empty())
        {
            int x = que.size();
            for (int i = 0; i < x; i++)
            {
                int m = que.front().first;
                int n = que.front().second;
                que.pop();
                image[m][n] = -1;
                if (m - 1 >= 0 && image[m - 1][n] == number)
                    que.push({m - 1, n});
                if (n - 1 >= 0 && image[m][n - 1] == number)
                    que.push({m, n - 1});
                if (m + 1 < image.size() && image[m + 1][n] == number)
                    que.push({m + 1, n});
                if (n + 1 < image[0].size() && image[m][n + 1] == number)
                    que.push({m, n + 1});
            }
        }
        for (int i = 0; i < image.size(); i++)
        {
            for (int j = 0; j < image[0].size(); j++)
            {
                if (image[i][j] == -1)
                    image[i][j] = color;
            }
        }
        return image;
    }
};
// @lc code=end
