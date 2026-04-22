#include <algorithm>
#include <cstddef>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> ans;
  set<vector<int>> ans2;

  void backtracking(vector<int> &nums, vector<int> &current, int index) {

    ans.push_back(current);

    for (int i = index; i < nums.size(); i++) {

      if (i > index && nums[i] == nums[i - 1])
        continue;

      current.push_back(nums[i]);
      backtracking(nums, current, i + 1);
      current.pop_back();
    }
  }

  vector<vector<int>> subsetsWithDup(vector<int> &nums) {

    vector<int> curr;
    sort(nums.begin(), nums.end());
    backtracking(nums, curr, 0);

    return ans;
  }
};

int main() {

  Solution s;

  vector<int> nums = {1, 2, 2};

  vector<vector<int>> ans = s.subsetsWithDup(nums);

  for (int i{}; i < ans.size(); i++) {

    for (int x : ans[i]) {
      cout << x << endl;
    }
    cout << endl;
  }

  return 0;
}