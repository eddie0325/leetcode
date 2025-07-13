/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder {
public:
    struct compare {
        bool operator()(int a, int b) {
            return a > b;
        }
    };

    priority_queue<int, vector<int>> smallPartHeap; // maxHeap
    priority_queue<int, vector<int>, compare> largePartHeap; // minHeap;
    
    MedianFinder() {
       // 維護兩個 heap:
        // - smallPartHeap: 儲存較小一半的數字（maxHeap）
        // - largePartHeap: 儲存較大一半的數字（minHeap）
        // 規則：
        // - 若總數是奇數，smallPartHeap 會多一個
        // - smallPartHeap.top() 是目前中位數
    }
    
    void addNum(int num) {
        // 根據值決定要放入哪一半
        if (smallPartHeap.empty() || num < smallPartHeap.top())
            smallPartHeap.push(num);
        else
            largePartHeap.push(num);
        
        // 較大的一半太多
        if (largePartHeap.size() > smallPartHeap.size()) {
            smallPartHeap.push(largePartHeap.top());
            largePartHeap.pop();
        }
        // 較小的一半太多
        else if (smallPartHeap.size() > largePartHeap.size() + 1) {
            largePartHeap.push(smallPartHeap.top());
            smallPartHeap.pop();
        }
    }   
    
    double findMedian() {
        if (smallPartHeap.size() == largePartHeap.size())
            return (double)(smallPartHeap.top() + largePartHeap.top()) / 2.0;
        return (double)smallPartHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

