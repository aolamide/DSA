 struct DListNode {
    pair<int, int> val;
    DListNode *next;
    DListNode *prev;
    DListNode() : val({0, 0}), next(nullptr), prev(nullptr) {}
    DListNode(pair<int, int> x) : val(x), next(nullptr), prev(nullptr) {}
    DListNode(pair<int, int> x, DListNode *next) : val(x), next(next), prev(nullptr) {}
};

class Twitter {
private:
    DListNode* tail = nullptr;
    unordered_map<int, unordered_set<int>> followers;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        if(!tail) {
            tail = new DListNode({ userId, tweetId });
        } else {
            DListNode* newNode = new DListNode({ userId, tweetId });
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        DListNode* currTail = tail;
        //get followers
        unordered_set<int>& following = followers[userId];

        //Load last ten tweets from followers
        while(currTail && feed.size() < 10) {
            int posterId = currTail->val.first;
            if(following.count(posterId) || posterId == userId) {
                feed.push_back(currTail->val.second);
            } 
            currTail = currTail->prev;
        }
        
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
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