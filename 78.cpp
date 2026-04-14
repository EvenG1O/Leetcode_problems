#include <iostream>
#include <vector>

using namespace std;

class sub {
public:
  vector<vector<int>> ans;
  vector<int> curr;

  void dfs(int index, vector<int> &nums) {

    if (index >= nums.size()) {
      ans.push_back(curr);
      return;
    }

    curr.push_back(nums[index]);
    dfs(index + 1, nums);

    curr.pop_back();

    dfs(index + 1, nums);
  }

  vector<vector<int>> subsets(vector<int> &nums) {

    dfs(0, nums);

    return ans;
  }
};

int main() {

  sub s;

  vector<int> t = {1, 2, 3};

  vector<vector<int>> ans = s.subsets(t);

  for (int i{}; i < ans.size(); i++) {
    for (auto x : ans[i]) {
      cout << x << " ";
    }
    cout << endl;
  }

  return 0;
}