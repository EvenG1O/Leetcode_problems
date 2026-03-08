#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int leastInterval(vector<char> &tasks, int n) {

  map<char, int> m;
  priority_queue<pair<int, int>> pq;
  queue<pair<int, int>> q;

  for (char x : tasks) {
    m[x] += 1;
  }

  for (auto const &[key, val] : m) {
    pq.push({val, 0});
  }

  int ans = 0;

  while (!pq.empty() || !q.empty()) {

    ans++;

    int c;
    if (!pq.empty()) {
      c = pq.top().first;
      if (c - 1 > 0) {
        q.push({c - 1, ans + n });
      }
      pq.pop();
    }

    if (!q.empty() && q.front().second == ans) {
      pq.push(q.front());
      q.pop();
    }
  }

  return ans;
}

int main() {
  vector<char> temp = {'A', 'A', 'A', 'B', 'B', 'B'};

  int ans = leastInterval(temp, 3);

  cout << ans;

  return 0;
}