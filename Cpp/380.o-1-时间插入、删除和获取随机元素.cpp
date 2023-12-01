/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

// @lc code=start
class RandomizedSet
{
public:
    set<int> init;
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (init.find(val) != init.end())
            return false;
        init.insert(val);
        return true;
    }

    bool remove(int val)
    {
        if (init.erase(val) == 0)
            return false;
        return true;
    }

    int getRandom()
    {
        int i = rand() % init.size();
        set<int>::iterator it = init.begin();
        advance(it, i);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
