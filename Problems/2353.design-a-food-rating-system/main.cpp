/*
 * @lc app=leetcode id=2353 lang=cpp
 *
 * [2353] Design a Food Rating System
 */

// @lc code=start
// #KEYPOINT priority_queue
// #define DEBUG
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;
class FoodRatings {
public:

    struct compareFood {
        bool operator()(pair<string, int> a, pair<string, int> b) {
            if(a.second != b.second) {
                return a.second < b.second;
            }
            return a.first > b.first;
        }
    };

    // hash用於快速查找，unordered_map
    unordered_map<string, pair<string, int>> foodData; // <name, <cuisine, rating>>
    // priority_queue在每次push時，確保top都是最高評分(maxHeap)
    unordered_map<string, priority_queue<pair<string, int>, vector<pair<string, int>>, compareFood>> ratedRanking; // cuisine, <name, rating>

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++) {            
            this->foodData[foods[i]] = {cuisines[i], ratings[i]};
            this->ratedRanking[cuisines[i]].push({foods[i], ratings[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        this->foodData[food].second = newRating;
        string cuisine = this->foodData[food].first;
        this->ratedRanking[cuisine].push({food, newRating});
    }
    
    string highestRated(string cuisine) {
        // TLE
        // auto foods = this->ratedRanking[cuisine];
        // pair<string, int> highest = foods.top();
        // while(highest.second != this->foodData[highest.first].second) {
        //     foods.pop();
        //     highest = foods.top();
        // }
        // return highest.first;

        // 直接存取較快
        pair<string, int> highest = this->ratedRanking[cuisine].top();
        while(highest.second != this->foodData[highest.first].second) {
            this->ratedRanking[cuisine].pop();
            highest = this->ratedRanking[cuisine].top();
        }
        return highest.first;


    }
};

#ifdef DEBUG
int main() {
    vector<string> foods = {"xxdcg","wfqdeytt","jqmfm","ukqbjikyx","aymciznrnw","qhjjrvr","wzcinxg","ikxj"};
    vector<string> cuisines = {"lruhtqy","lruhtqy","lruhtqy","lruhtqy","lruhtqy","lruhtqy","lruhtqy","lruhtqy"};
    vector<int> ratings = {8,6,1,17,20,2,17,14};
    FoodRatings aaa(foods, cuisines, ratings);
    string result;
    result = aaa.highestRated("lruhtqy");
    aaa.changeRating("wfqdeytt", 17);
    aaa.changeRating("aymciznrnw", 9);
    result = aaa.highestRated("lruhtqy");
    aaa.changeRating("ukqbjikyx", 10);
    result = aaa.highestRated("lruhtqy");
}
#endif

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
// @lc code=end

