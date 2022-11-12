class MedianFinder {
public:
    priority_queue<int> lows;
    priority_queue<int, vector<int>, greater<int>> highs;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lows.push(num);
        highs.push(lows.top());
        lows.pop();
        
        if (highs.size() > lows.size()) {
            lows.push(highs.top());
            highs.pop();
        }
    }
    
    double findMedian() {
        if (lows.size() > highs.size()) return lows.top();
        
        return (lows.top() + highs.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */