class Twitter {
public:
    vector<pair<int , int>> st;
     vector<vector<bool>> followed;
    Twitter() {
        
        followed.resize(501 , vector<bool>(501, false));
    }
    
    void postTweet(int userId, int tweetId) {
        st.push_back({userId , tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        int count = 0;
        for(int i=st.size()-1;i>=0 && count<10;i--){
            // cout<<st[i].first<<" ";
            // cout<<st[i].second<<" ";
            
            if(userId == st[i].first || followed[userId][st[i].first]){
                ans.push_back(st[i].second);
                count++;
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followed[followerId][followeeId] = true;
        // followed[followeeId][followerId] = true;
    }
    
    void unfollow(int followerId, int followeeId) {
         followed[followerId][followeeId] = false;
        //   followed[followeeId][followerId] = false;
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