#include <bits/stdc++.h>
using namespace std;

class Twitter {
private:  //i can access these things using public functions only
    vector<pair<int,int>>posts;
    unordered_map<int, unordered_map<int, int>>follows; //m[followerID][FolloweeID] = 1 or 0      [int][int] = value
public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        posts.push_back(make_pair(userId, tweetId));
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>feed;
        int count = 0;
        for(int i = posts.size() - 1; i >= 0 && count < 10; i--) //vector ka last 10 elements using count
            if(posts[i].first == userId || follows[userId][posts[i].first])
                feed.push_back(posts[i].second), count++;
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId][followeeId] = 1; //followee follows persond with id = followerID
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId][followeeId] = 0;
    }
};