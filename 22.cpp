#include <algorithm>
#include <cstddef>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> ans;
  string curr = "";

  void dfs(int n, int close, int open) {

    if(close > n) return;
    if (close == open && close == n) {
      ans.push_back(curr);
      return;
    }

    if (close > open)
      return;

    if (open < n) {
      curr += '(';
      dfs(n, close, open + 1);
      curr.pop_back();
    }

    if (open > close) {
      curr += ')';
      dfs(n, close + 1, open);
      curr.pop_back();
    }
  }

  vector<string> generateParenthesis(int n) {

    dfs(n, 0, 0);

    return ans;
  }
};

int main() {

  Solution s;

  vector<string> ans;

  vector<string> c = s.generateParenthesis(3);

  for (string s : c) {

    cout << s << endl;
  }

  return 0;
}