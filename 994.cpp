#include <iostream>
#include <queue>
#include <set>
#include <utility>
#include <vector>

using namespace std;

class Solution {

public:
  set<pair<int, int>> visited;
  int numRows{};
  int numColumns{};
  queue<pair<int, int>> q;

  int ans{};

  void dfs(vector<vector<int>> &grid, int c, int r) {

    if (r > numRows - 1 || r < 0)
      return;

    if (c > numColumns - 1 || c < 0)
      return;

    if (visited.count({c, r}))
      return;

    visited.insert({c, r});

    if (grid[c][r] == 0)
      return;

    q.push({c + 1, r});
    q.push({c - 1, r});

    q.push({c, r + 1});

    q.push({c, r - 1});
  }

  int orangesRotting(vector<vector<int>> &grid) {

    numColumns = grid.size();
    numRows = grid[0].size();

    for (int i{}; i < grid.size(); i++) {
      for (int j{}; j < grid[0].size(); j++) {

        if (grid[i][j] == 2)
          q.push({i, j});
      }
    }

    while (!q.empty()) {
      int s = q.size();

      for (int i{}; s > i; i++) {
        dfs(grid, q.front().first, q.front().second);

        q.pop();
      }

      if (!q.empty()) ans++;
    }

    for (int i{}; i < grid.size(); i++) {
      for (int j{}; j < grid[0].size(); j++) {

        if (grid[i][j] == 1 && !visited.count({i,j}))
          return -1;
      }
    }


    return ans > 0 ? ans - 1 : 0;
  }
};

int main() {

  Solution s;

  std::vector<std::vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};

  int ans = s.orangesRotting(grid);

  cout << ans << endl;

  return 0;
}