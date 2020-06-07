/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start
#include <set>
#include <string>
#include <vector>
using namespace std;

class Trie {
   public:
    Trie() {
        next = vector<Trie*>(26, nullptr);
        is_end = false;
    }

    void addWord(const string& word) {
        Trie* node = this;
        for (char ch : word) {
            int index = ch - 'a';
            if (!node->next[index]) node->next[index] = new Trie();
            node = node->next[index];
        }
        node->is_end = true;
    }

   public:
    vector<Trie*> next;
    bool is_end;
};

class Solution {
   public:
    vector<string> findWords(vector<vector<char> >& board,
                             vector<string>& words) {
        Trie* root = new Trie();
        for (string& word : words) {
            root->addWord(word);
        }

        set<string> wordSet;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, "", wordSet);
            }
        }

        vector<string> res(wordSet.begin(), wordSet.end());
        return res;
    }

    void dfs(vector<vector<char> >& board, int i, int j, Trie* root,
             string word, set<string>& wordSet) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            board[i][j] == ' ')
            return;

        if (root->next[board[i][j] - 'a']) {
            word.push_back(board[i][j]);
            root = root->next[board[i][j] - 'a'];
            if (root->is_end) wordSet.insert(word);
            char ch = board[i][j];
            board[i][j] = ' ';
            dfs(board, i + 1, j, root, word, wordSet);
            dfs(board, i - 1, j, root, word, wordSet);
            dfs(board, i, j + 1, root, word, wordSet);
            dfs(board, i, j - 1, root, word, wordSet);
            board[i][j] = ch;
        }
    }
};
// @lc code=end
