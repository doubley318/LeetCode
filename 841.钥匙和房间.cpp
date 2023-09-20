/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 */

// @lc code=start
class Solution {
public:
    vector<bool> vedrooms = vector<bool>(1005, false);

    void VisitRooms(vector<vector<int>>& rooms, int now)
    {
        if (vedrooms[now]) {
            return;
        }
        vedrooms[now] = true;
        for (int i = 0; i < rooms[now].size(); i++) {
            VisitRooms(rooms, rooms[now][i]);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        VisitRooms(rooms, 0);
        for (int i = 0; i < rooms.size(); i++) {
            if (vedrooms[i] == false) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
