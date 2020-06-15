/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */

// @lc code=start
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
   public:
    LRUCache(int capacity) : m_capacity(capacity) {}

    int get(int key) {
        auto itr = m_map.find(key);
        if (itr == m_map.end()) return -1;
        pair<int, int> tmp = *m_map[key];
        m_cache.erase(m_map[key]);
        m_cache.push_front(tmp);
        m_map[key] = m_cache.begin();
        return tmp.second;
    }

    void put(int key, int value) {
        auto itr = m_map.find(key);
        if (itr == m_map.end()) {
            if (m_cache.size() == m_capacity) {
                auto lastPair = m_cache.back();
                int lastKey = lastPair.first;
                m_map.erase(lastKey);
                m_cache.pop_back();
            }

            m_cache.push_front(make_pair(key, value));
            m_map[key] = m_cache.begin();
        } else {
            m_cache.erase(m_map[key]);
            m_cache.push_front(make_pair(key, value));
            m_map[key] = m_cache.begin();
        }
    }

   private:
    int m_capacity;
    // 双向链表，结点内容为元组（key, value）
    list<pair<int, int>> m_cache;
    // 哈希表，value为key在双向链表上的位置
    unordered_map<int, list<pair<int, int>>::iterator> m_map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
