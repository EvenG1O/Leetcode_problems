#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  queue<pair<string, int>> q; // lock , turns
  set<string> visited;
  int currentTurns{};

  vector<string> children(string &s) {
    int size = s.length();
    vector<string> ans;

    for (int i{}; i < size; i++) {

      string s2 = s, s3 = s;

      int originalDigit = s[i] - '0';
      char temp = static_cast<char>(((originalDigit + 1) % 10) + '0');

      s2[i] = temp;

      ans.push_back(s2);
      temp = static_cast<char>(((originalDigit - 1 + 10) % 10) + '0');
      s3[i] = temp;
      ans.push_back(s3);
    }
    return ans;
  }

  int openLock(vector<string> &deadends, string target) {

    for (const string &x : deadends) {
      visited.insert(x);
    }

    if (visited.count("0000"))
      return -1;

    q.push({"0000", currentTurns});
    visited.insert({"0000"});
    while (!q.empty()) {
      string curr = q.front().first;
      int currTurns = q.front().second;
      q.pop();
      if (curr == target)
        return currTurns;

      currentTurns++;

      vector<string> currChildren = children(curr);

      for (string c : currChildren) {
        if (!visited.count(c)) {
          visited.insert(c);
          q.push({c, currTurns + 1});
        }
      }
    }
    return -1;
  }
};

int main() {

  Solution s;
  vector<string> test = {"0201", "0101", "0102", "1212", "2002"};

  int ans = s.openLock(test, "0202");

  cout << ans << endl;

  return 0;
}