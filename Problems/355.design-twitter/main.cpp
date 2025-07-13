/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */

// @lc code=start
class Twitter {
public:
    int time_stamp = 0;
    unordered_map<int, vector<pair<int, int>>> userTweets; // (userId, vector(time, tweetId))
    unordered_map<int, unordered_set<int>> followMap;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({time_stamp++, tweetId});
        follow(userId, userId);
    }
    
    vector<int> getNewsFeed(int userId) {
        // 取得這個使用者的追蹤人清單
        auto &followList = followMap[userId];
        // 每個追蹤對象最新的文章Heap (time, (userId, index))
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int, int>>>> maxHeap;
        for (auto &userId: followList) {
            // 取得follow對象的tweet列表
            auto tweetList = userTweets[userId];
            if (tweetList.size() == 0) continue;
            // 只放入對象最新的tweet
            int latestIndex = tweetList.size() - 1;
            auto tweet = tweetList[latestIndex];
            maxHeap.push({tweet.first, {userId, latestIndex}});
        }

        vector<int> ans;
        while(!maxHeap.empty() && ans.size() < 10) {
            auto topEntry = maxHeap.top();
            auto tweet = topEntry.second;
            auto userId = tweet.first;
            auto tweetIndex = tweet.second;
            auto tweetId = userTweets[userId][tweetIndex].second;
            ans.push_back(tweetId);
            maxHeap.pop();
            
            // 再放入該對象下一篇tweet
            if (tweetIndex > 0) {
                auto nextTweet = userTweets[userId][tweetIndex - 1];
                maxHeap.push({nextTweet.first, {userId, tweetIndex - 1}});
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId)
            return;
        followMap[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end

