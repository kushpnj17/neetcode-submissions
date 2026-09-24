class Twitter {
    unordered_map<int, vector<pair<int, int>>> posts; // time, tweetID

    // set of all the people that a user follows
    unordered_map<int, unordered_set<int>> following;

    int time;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        
        for(auto n : posts[userId]){
            pq.push({n.first, n.second});
            if(pq.size() > 10){
                pq.pop();
            }
        }

        for(int s : following[userId]){
            for(auto n : posts[s]){
                pq.push({n.first, n.second});
                if(pq.size() > 10){
                    pq.pop();
                }
            }
        }

        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
