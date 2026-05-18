#include <cmath>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

class Solution {

public:
  set<pair<int, int>> s;

  int rowSize{};
  int columnSize{};

  int dfs(vector<vector<int>> &grid, int i, int j) {
    int currentSum{};

    if(s.count({i, j})) return currentSum;

    if (0 > i || 0 > j || rowSize <= j || i >= columnSize) {
        s.insert({i, j});
        return ++currentSum;
      
    }

    if (grid[i][j] == 1) {
      if (!s.count({i, j})) {
        s.insert({i, j});
        currentSum += dfs(grid, i + 1, j);
        currentSum += dfs(grid, i - 1, j);
        currentSum += dfs(grid, i, j + 1);
        currentSum += dfs(grid, i, j - 1);
      }

    } else {
      if (!s.count({i, j})) {
        currentSum++;
      }
    }
    return currentSum;
  }

  int islandPerimeter(vector<vector<int>> &grid) {
        columnSize = grid.size();
        rowSize = grid[0].size();
        int ans{};
        bool flag = false;
        for(int i{} ; i < columnSize; i++){
            for(int j{}; j < rowSize; j++){
              if(grid[i][j] == 1) 
              {
                ans += dfs(grid, i, j);
                flag = true;    
              } 
            }
            if(flag == true) break;
        }

        return ans;

  }
};

int main() {

  Solution s;


  vector<vector<int>> test = {
      {1,0}};


      int ans = s.islandPerimeter(test);

      cout<<ans<<endl;

  return 0;
}