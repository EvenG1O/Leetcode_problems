#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> cache;

  int dfs(int i, int size) {

    if (i == size)
      return 1;
    if (i > size)
      return 0;

    if (cache[i] != -1)
      return cache[i];

    cache[i] = dfs(i + 1, size) + dfs(i + 2, size);

    return cache[i];
  }

  int climbStairs(int n) {

    cache.assign(n + 1, -1);

    return dfs(0, n);
  }
};

int main() {

  Solution s;

  int ans = s.climbStairs(4);
  cout << ans << endl;

  return 0;
}