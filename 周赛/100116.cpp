int findChampion(int n, vector<vector<int>>& edges)
{
    vector<int> nums(n, 0);
    for (int i = 0; i < edges.size(); i++) {
        nums[edges[i][1]]++;
    }
    int ret = -1;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0 && ret == -1) {
            ret = i;
        } else if (nums[i] == 0) {
            return -1;
        }
    }
    return ret;
}