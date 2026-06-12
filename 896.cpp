#include <ios>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool isMonotonic(vector<int> &nums) {
    bool increasing = false;
    bool decreasing = false;

    int prev{};

    for (int i{}; i < nums.size(); i++) {

      if (i > 0) {
        if (nums[i] > prev)
          increasing = true;
        if (nums[i] < prev)
          decreasing = true;
      }

      if (increasing == true && decreasing == true)
        return false;
      prev = nums[i];
      cout << i << endl;
    }
    return true;
  }
};

int main() {

  Solution s;

  vector<int> test = {1, 2, 2, 3};

  bool ans = s.isMonotonic(test);

  cout << boolalpha << ans << endl;

  return 0;
}