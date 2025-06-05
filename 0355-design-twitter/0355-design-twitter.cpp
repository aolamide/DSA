 struct TListNode {
    pair<int, int> val;
    TListNode *next;
    TListNode(pair<int, int> x) : val(x), next(nullptr) {}
};

class Twitter {
private:
    TListNode* head = nullptr;
    unordered_map<int, unordered_set<int>> followers;
public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        //create new node and set node as new head
        TListNode* newTweet = new TListNode({ userId, tweetId });
        newTweet->next = head;
        head = newTweet;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        TListNode* currHead = head;

        //get followers
        unordered_set<int>& following = followers[userId];

        //Load last ten tweets from followers or self
        while(currHead && feed.size() < 10) {
            int posterId = currHead->val.first;

            if(following.count(posterId) || posterId == userId) {
                feed.push_back(currHead->val.second);
            }

            currHead = currHead->next;
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