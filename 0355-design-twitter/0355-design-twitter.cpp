class Twitter {
public:
    int time = 0;

    // user -> list of {time, tweetId}
    vector<vector<pair<int, int>>> tweets;

    // follower -> followees
    vector<vector<bool>> followed;

    Twitter() {
        tweets.resize(501);
        followed.resize(501, vector<bool>(501, false));
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans;

        // max heap:
        // {time, tweetId, userId, index}
        priority_queue<
            tuple<int, int, int, int>
        > pq;

        // User's own tweets
        if (!tweets[userId].empty()) {
            int i = tweets[userId].size() - 1;
            auto [t, id] = tweets[userId][i];
            pq.push({t, id, userId, i});
        }

        // Tweets from followed users
        for (int followee = 1; followee <= 500; followee++) {
            if (followed[userId][followee] && !tweets[followee].empty()) {
                int i = tweets[followee].size() - 1;
                auto [t, id] = tweets[followee][i];
                pq.push({t, id, followee, i});
            }
        }

        // Get latest 10 tweets
        while (!pq.empty() && ans.size() < 10) {
            auto [t, tweetId, user, index] = pq.top();
            pq.pop();

            ans.push_back(tweetId);

            // Get previous tweet from the same user
            if (index > 0) {
                int newIndex = index - 1;
                auto [newTime, newTweetId] = tweets[user][newIndex];

                pq.push({
                    newTime,
                    newTweetId,
                    user,
                    newIndex
                });
            }
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        followed[followerId][followeeId] = true;
    }

    void unfollow(int followerId, int followeeId) {
        followed[followerId][followeeId] = false;
    }
};