#include <algorithm>
#include <cstddef>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> ans;
  set<vector<int>> se;

  void dfs(vector<int> &candidates, vector<int> &currentCandidates, int index,
           int target, int currentSum) {
    if (currentSum == target) {
      if (se.count(currentCandidates))
        return;


      ans.push_back(currentCandidates);
      se.insert(currentCandidates);
      return;
    }

    

    if (currentSum > target || index >= candidates.size())
      return;

    for(int i = index; i < candidates.size(); i++)
    {

      if (i > index && candidates[i] == candidates[i - 1] ) {
        continue;
      }

      if(currentSum + candidates[i] > target) break;



      currentCandidates.push_back(candidates[i]);
      dfs(candidates, currentCandidates, i + 1, target, currentSum + candidates[i]);
      currentCandidates.pop_back();





    }



  }

  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<int> currentCandidates;
    sort(candidates.begin(), candidates.end());
    dfs(candidates, currentCandidates, 0, target, 0);

    return ans;
  }
};

int main() {

  Solution s;

  vector<int> t = {10, 1, 2, 7, 6, 1, 5};

  vector<vector<int>> ans = s.combinationSum2(t, 8);

  for (size_t i = 0; i < ans.size(); i++) {

    for (int x : ans[i]) {
      cout << x << endl;
    }
    cout << endl;
  }

  return 0;
}