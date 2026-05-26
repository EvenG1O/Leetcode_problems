#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int numRows{};
  int numColumns{};
  set<pair<int, int>> s;

  int dfs(vector<vector<int>> &grid, int r, int c) {

    int currentSize{};

    if (r >= numRows || 0 > r)
      return 0;
    if (c >= numColumns || 0 > c)
      return 0;

    if (s.count({r, c}))
      return 0;

    s.insert({r, c});

    if (grid[r][c] == 0)
      return 0;
    if (grid[r][c] == 1)
      currentSize++;

    int left = dfs(grid, r - 1, c);
    int right = dfs(grid, r + 1, c);
    int down = dfs(grid, r, c - 1);
    int up = dfs(grid, r, c + 1);

    currentSize += left + right + down + up;

    return currentSize;
  }

  int maxAreaOfIsland(vector<vector<int>> &grid) {

    if (grid.empty())
      return 0;

    numColumns = grid[0].size();
    numRows = grid.size();

    int ans{};

    for (int i{}; i < numRows; i++) {
      for (int j{}; j < numColumns; j++) {

        if (grid[i][j] == 1) {

          ans = max(ans, dfs(grid, i, j));
        }
      }
    }

    return ans;
  }
};

int main() {

  Solution s;

  std::vector<std::vector<int>> grid = {
      {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
      {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
      {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

  int ans = s.maxAreaOfIsland(grid);

  cout << ans << endl;

  return 0;
}