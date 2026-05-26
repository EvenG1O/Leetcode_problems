#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  set<pair<int, int>> s;
  int numRows{};
  int numCols{};

  void dfs(vector<vector<char>> &grids, int r, int c) {

if (r < 0 || r >= numRows)
      return;
    if (c < 0 || c >= numCols)
      return;

    if (s.count({r, c}))
      return;
    s.insert({r, c});
    if (grids[r][c] == '0')
      return;

    dfs(grids, r + 1, c);
    dfs(grids, r - 1, c);
    dfs(grids, r, c + 1);

    dfs(grids, r, c - 1);
  }

  int numIslands(vector<vector<char>> &grid) {

    numCols = grid[0].size();
    numRows = grid.size();
    int ans{};

    for (int i{}; i < numRows; i++) {
      for (int j{}; j < numCols; j++) {

        if (grid[i][j] == '1' && !s.count({i, j})) {
          ans++;
          dfs(grid, i, j);
        }
      }
    }

    return ans;
  }
};

int main() {

  Solution s;

  std::vector<std::vector<char>> grid = {{'1', '1', '1', '1', '0'},
                                         {'1', '1', '0', '1', '0'},
                                         {'1', '1', '0', '0', '0'},
                                         {'0', '0', '0', '0', '0'}};

  int ans = s.numIslands(grid);

  cout << ans << endl;

  return 0;
}