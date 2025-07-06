/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
// #KEYPOINT list
class LRUCache {
private:
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap; // (key: node::iterator)
    list<pair<int, int>>lruList; // front:recent back:old
    int cacheCapacity;
    
public:
    LRUCache(int capacity) {
        cacheCapacity = capacity;
    }
    
    int get(int key) {
        auto it = cacheMap.find(key);
        if (it != cacheMap.end()) {
            lruList.splice(lruList.begin(), lruList, it->second);
            return it->second->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = cacheMap.find(key);
        if (it != cacheMap.end()) {
            auto nodeIt = it->second;
            nodeIt->second = value;
            // 移到front
            lruList.splice(lruList.begin(), lruList, nodeIt);
        }
        else {
            if (lruList.size() == cacheCapacity) { // 滿了
                auto oldData = lruList.back();
                lruList.pop_back();
                cacheMap.erase(oldData.first);
            }
            pair<int, int> data(key, value);
            lruList.push_front(data);
            cacheMap[key] = lruList.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

