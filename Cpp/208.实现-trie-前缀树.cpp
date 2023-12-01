/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie
{
public:
    struct Trie_node
    {
        bool end = false;
        Trie_node *next[26];
    };

    Trie_node *head;
    Trie()
    {
        head = new Trie_node();
    }

    void insert(string word)
    {
        Trie_node *tmp = head;
        for (int i = 0; i < word.size(); i++)
        {
            if (tmp->next[word[i] - 'a'] == nullptr)
                tmp->next[word[i] - 'a'] = new Trie_node();
            tmp = tmp->next[word[i] - 'a'];
        }
        tmp->end = true;
    }

    bool search(string word)
    {
        Trie_node *tmp = head;
        for (int i = 0; i < word.size(); i++)
        {
            if (tmp->next[word[i] - 'a'] == nullptr)
                return false;
            tmp = tmp->next[word[i] - 'a'];
        }
        return tmp->end;
    }

    bool startsWith(string prefix)
    {
        Trie_node *tmp = head;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (tmp->next[prefix[i] - 'a'] == nullptr)
                return false;
            tmp = tmp->next[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
