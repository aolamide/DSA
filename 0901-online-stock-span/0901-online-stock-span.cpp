class StockSpanner {
public:
    stack <pair<int, int>> s;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(s.empty()) {
            s.push({price, 1});
            return 1;
        } else {
            int count = 1;
            while(!s.empty() && s.top().first <= price) {
                auto top = s.top();
                count += top.second;
                s.pop();
            }
            s.push({price, count});
            return count;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */