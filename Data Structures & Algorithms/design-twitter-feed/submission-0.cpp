typedef pair<int, int> pii;

struct Compare {
    bool operator()(const pii p1, const pii p2) const {
        return p1.second < p2.second; // max heap
    }
};

class Twitter {
public:
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, unordered_set<int>> followed_by;
    // unordered_map<int, vector<int>> tweets;
    
    unordered_map<int, set<pii, Compare>> recentTweets; // recentTweets[userId] = {tweetId, time}
    int time = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        recentTweets[userId].insert({tweetId, time++});
        if (recentTweets[userId].size() > 10) {
            recentTweets[userId].erase(recentTweets[userId].begin());
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        set<pii, Compare> allTweets(recentTweets[userId].begin(), recentTweets[userId].end());
        for (int followee: follows[userId]) {
            for (auto [id, time]: recentTweets[followee]) {
                allTweets.insert({id, time});
                if (allTweets.size() > 10) {
                    allTweets.erase(allTweets.begin());
                }
            }
        }
        vector<int> res;
        for (auto [id, _]: allTweets) {
            res.push_back(id);
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
        followed_by[followeeId].insert(followerId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
        followed_by[followeeId].erase(followerId);
    }
};
