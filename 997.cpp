#include <ios>
#include <iostream>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {

public:
  int findJudge(int n, vector<vector<int>> &trust) {

    vector<int> inc(n + 1, 0), out(n + 1, 0);

    for (int i{}; i < trust.size(); i++) {

      out[trust[i][0]]++;
      inc[trust[i][1]]++;
    }

    for (int i = 1; i <= n; i++) {

      if (inc[i] == n - 1 && out[i] == 0)
        return i;
    }

    return -1;
  }
};

int main() {

  Solution s;

  int n = 1;
  vector<vector<int>> trust = {};

  int ans = s.findJudge(n, trust);

  cout << ans << endl;

  return 0;
}