#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  unordered_set<int> s;

  int sum(vector<int> &nums) {
    int ans{};
    for (int x : nums) {

      ans += x;
    }
    return ans;
  }

  bool canPartition(vector<int> &nums) {

    if (sum(nums) % 2)
      return false;

    int target = sum(nums) / 2;
    s.insert(0);

    for (int i{}; i < nums.size(); i++) {

      unordered_set<int> tempSet;

      for (int x : s) {
        int currentSum = nums[i] + x;

        if (currentSum == target)
          return true;

        if (currentSum < target)
          tempSet.insert(currentSum);
      }

      for (int x : tempSet) {
        s.insert(x);
      }
    }

    return false;
  }
};

int main() {

  Solution s;

  vector<int> test = {1, 5, 11, 5};

  bool ans = s.canPartition(test);

  cout << boolalpha << ans << endl;

  return 0;
}