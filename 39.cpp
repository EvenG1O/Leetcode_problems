#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;



class Solution{
  public:
vector<vector<int>> ans;
int total = 0;

void dfs(vector<int> &candidates, vector<int> &current, int i, int currentSum,
         int target) {
  if (currentSum == target) {
    ans.push_back(current);
    return;
  }

  if (candidates.size() <= i || currentSum > target )
    return;

  current.push_back(candidates[i]);
  dfs(candidates, current, i, currentSum + candidates[i], target);


  current.pop_back();

  dfs(candidates, current, i + 1, currentSum, target);

}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
  vector<int> nums;
  dfs(candidates, nums, 0, 0, target);

  return ans;
}



};

int main() {

  Solution s;

  vector<int> t = {2, 3, 6, 7};

  vector<vector<int>> ans = s.combinationSum(t,7);


  for ( size_t i =0; i < ans.size(); i++) {

    for (int x : ans[i]) {
        cout<<x<<endl;
    }
    cout<<endl;



  }

  return 0;
}