#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_map<int, int> map;

    for (int i{}; i < nums.size(); i++) {
      if (map.count(nums[i])) {
        if (abs(i - map[nums[i]]) <= k)
          return true;
      }

      map[nums[i]] = i;
    }

    return false;
  }
};

int main() {
  vector<int> test = {-1,-1};

  Solution s;

  bool ans = s.containsNearbyDuplicate(test, 1);

  if (ans)
    cout << "true" << endl;
  else
    cout << "false" << endl;

  return 0;
}