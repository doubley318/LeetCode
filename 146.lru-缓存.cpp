/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start

struct Node
{
    int key;
    int val;
    Node *next;
    Node *prev;

    Node(int _key, int _val)
    {
        key = _key;
        val = _val;
        next = nullptr;
        prev = nullptr;
    }

    Node()
    {
        key = 0;
        val = 0;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache
{
public:
    unordered_map<int, Node *> cache;
    Node *virhead;
    Node *virtail;
    int capacity;
    LRUCache(int capacity)
    {
        virhead = new Node();
        virtail = new Node();
        virhead->next = virtail;
        virtail->prev = virhead;
        this->capacity = capacity;
    }

    int get(int key)
    {
        unordered_map<int, Node *>::iterator it = cache.find(key);
        if (it == cache.end())
            return -1;
        Node *tmp = it->second;
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        tmp->next = virhead->next;
        tmp->prev = virhead;
        virhead->next->prev = tmp;
        virhead->next = tmp;
        return tmp->val;
    }

    void put(int key, int value)
    {
        unordered_map<int, Node *>::iterator it = cache.find(key);
        Node *tmp;
        if (it != cache.end())
        {
            tmp = it->second;
            tmp->val = value;
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
        }
        else
        {
            if (cache.size() == capacity)
            {
                tmp = virtail->prev;
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
                it = cache.find(tmp->key);
                cache.erase(it);
                delete (tmp);
            }
            tmp = new Node(key, value);
            cache.insert({key, tmp});
        }
        tmp->next = virhead->next;
        tmp->prev = virhead;
        virhead->next->prev = tmp;
        virhead->next = tmp;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
