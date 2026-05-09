
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {

    int l = 0;

    int currentSum{};

    int minWindowSize = INT_MAX;

    for (int r = 0; r < nums.size(); r++) {
      currentSum += nums[r];
      while (target <= currentSum) {
        minWindowSize = min(minWindowSize, r - l + 1);
        currentSum -= nums[l];
        l++;
      }
    }

    return minWindowSize == INT_MAX ? 0 : minWindowSize;
  }
};

int main() {

  Solution s;

  vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};

  int ans = s.minSubArrayLen(11, nums);

  cout << ans << endl;

  return 0;
}