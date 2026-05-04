#include <cmath>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Twitter {
private:
  vector<pair<int, int>> tweets;
  unordered_map<int, unordered_set<int>> users;

public:
  Twitter() {}

  void postTweet(int userId, int tweetId) {
    tweets.push_back({userId, tweetId});
  }

  vector<int> getNewsFeed(int userId) {

    vector<int> ans;

    for (int i = tweets.size() - 1; i >= 0; i--) {
      if (ans.size() >= 10)
        break;

      int author = tweets[i].first;
      int tw = tweets[i].second;

      if (author == userId || users[userId].count(author))
        ans.push_back(tw);
    }

    return ans;
  }

  void follow(int followerId, int followeeId) {

    if (followerId != followeeId)
      users[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {

    users[followerId].erase(followeeId);
  }
};

int main() {
  Twitter *twitter = new Twitter();

  twitter->postTweet(1, 5); // User 1 posts a new tweet (id = 5).
  vector<int> t =
      twitter->getNewsFeed(1); // User 1's news feed should return a list with 1
                               // tweet id -> [5]. return [5]
  for (int x : t) {
    cout << x << endl;
  }
  twitter->follow(1, 2);    // User 1 follows user 2.
  twitter->postTweet(2, 6); // User 2 posts a new tweet (id = 6).
  vector<int> t2 = twitter->getNewsFeed(
      1); // User 1's news feed should return a list with 2 tweet ids -> [6, 5].
          // Tweet id 6 should precede tweet id 5 because it is posted after
          // tweet id 5.
  for (int x : t2) {
    cout << x << endl;
  }
  twitter->unfollow(1, 2); // User 1 unfollows user 2.
  vector<int> t3 = twitter->getNewsFeed(
      1); // User 1's news feed should return a list with 1 tweet id -> [5],
          // since user 1 is no longer following user 2.
  for (int x : t3) {
    cout << x << endl;
  }

  return 0;
}