// https://leetcode.cn/problems/lru-cache-lcci/description/
#include <stdc++.h>
using namespace std;
// todo
class LRUCache {
public:
    LRUCache(int capacity) {
        this->total_capacity = capacity;
        // key_value_map = vector<pair<int, int>>(10001, pair<int, int>(0, 0));
    }
    
    int get(int key) {
        if (key_value_map.count(key) != 0) {
            key_value_map[key].second++;
            return key_value_map[key].first;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (key_value_map.size() == total_capacity) {
            if (key_value_map.count(key) == 0) {
                // 插入新的
                // 获取频率最低
                // key_value_map.erase()
                std::sort(key_value_map.begin(), key_value_map.end());
            } else {
                key_value_map[key].first = value;
            }
        } else if (key_value_map.size() < total_capacity) {
            if (key_value_map.count(key) == 0) {
                // 插入新的
                key_value_map[key].first = value;
                key_value_map[key].second++;
            } else {
                key_value_map[key].first = value;
                key_value_map[key].second = 1;
            }
        }
    }

    int total_capacity = 0;
    int cur_capacity = 0;
    // value, count
    // vector<pair<int, int>> key_value_map;
    // 存频率 pos, count
    vector<pair<int, int>> count_map;

    unordered_map<int, pair<int, int>> key_value_map;
};