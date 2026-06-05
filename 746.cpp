

#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {

    cost.push_back(0);
    int ans{};

    for (int i = cost.size() - 3; i >= 0; i--) {
      cost[i] += min(cost[i + 1], cost[i + 2]);
    }

    return min(cost[0], cost[1]);
  }
};

int main() {

    Solution s;

  vector<int> t = {10, 15, 20};

  int ans =  s.minCostClimbingStairs(t);

  cout<<ans<<endl;

  return 0;
}