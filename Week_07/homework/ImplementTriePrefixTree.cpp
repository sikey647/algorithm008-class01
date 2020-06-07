/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Trie {
   public:
    /** Initialize your data structure here. */
    Trie() {}

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *node = this;
        for (char ch : word) {
            ch -= 'a';
            if (!node->next[ch]) node->next[ch] = new Trie();
            node = node->next[ch];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *node = this;
        for (char ch : word) {
            ch -= 'a';
            if (!node->next[ch]) return false;
            node = node->next[ch];
        }
        return node->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix) {
        Trie *node = this;
        for (char ch : prefix) {
            ch -= 'a';
            if (!node->next[ch]) return false;
            node = node->next[ch];
        }
        return true;
    }

   private:
    Trie *next[26] = {};
    bool isEnd = false;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
