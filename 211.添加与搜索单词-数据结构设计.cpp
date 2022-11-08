/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
struct TrieNode
{
    // 孩子
    vector<TrieNode *> child;
    // 是否是最后的节点了
    bool isEnd;
    TrieNode()
    {
        this->child = vector<TrieNode *>(26, nullptr);
        this->isEnd = false;
    }
};

class WordDictionary
{
private:
    TrieNode *trie;

public:
    WordDictionary()
    {
        trie = new TrieNode();
    }

    void addWord(string word)
    {
        TrieNode *tmp = trie;
        for (int i = 0; i < word.size(); i++)
        {
            if (tmp->child[word[i] - 'a'] == nullptr)
            {
                tmp->child[word[i] - 'a'] = new TrieNode();
            }
            tmp = tmp->child[word[i] - 'a'];
        }
        tmp->isEnd = true;
    }

    bool search(string word)
    {
        return dfs(word, 0, trie);
    }

    bool dfs(const string &word, int index, TrieNode *node)
    {
        if (index == word.size())
        {
            return node->isEnd;
        }
        char ch = word[index];
        if (ch != '.')
        {
            TrieNode *child = node->child[ch - 'a'];
            if (child != nullptr && dfs(word, index + 1, child))
            {
                return true;
            }
        }
        else if (ch == '.')
        {
            for (int i = 0; i < 26; i++)
            {
                TrieNode *child = node->child[i];
                if (child != nullptr && dfs(word, index + 1, child))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
