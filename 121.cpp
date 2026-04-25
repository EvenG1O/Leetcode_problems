#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {

    int ans{};

    int l = 0;
    int r = 1;

    while (r < prices.size()) {

      if ((prices[r] - prices[l]) > ans) {
        ans = prices[r] - prices[l];
      }

      if (prices[l] > prices[r])
        l = r;

      r++;
    }

    return ans;
  }
};

int main() {

    Solution s;
  vector<int> testCase = {7,6,4,3,1};

  int ans = s.maxProfit(testCase);
  cout<<ans;

  return 0;
}