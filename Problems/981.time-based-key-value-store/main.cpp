/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start
class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> timeMap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (timeMap.find(key) == timeMap.end())
            return "";
        auto &data = timeMap[key];
        int left = 0;
        int right = data.size() - 1;
        int ans = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if (data[mid].first <= timestamp) {
                left = mid + 1;
                ans = mid;
            }
            else {
                right = mid - 1;
            }
        }
        if (ans == -1)
            return "";
        return data[ans].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end

