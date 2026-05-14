#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> ans;
  vector<string> temp;

  // working
  bool checkIfPalindrome(string s, int l, int r) {

    while (r >= l) {

      if (s[l] != s[r])
        return false;
      l++;
      r--;
    }

    return true;
  }

  void dfs(string s, int i, int j) {

    if (i == s.length()) {
      ans.push_back(temp);
      return;
    }

    if(j >= s.length()) return;

    if (checkIfPalindrome(s, i, j)) {
      temp.push_back(s.substr(i, j - i + 1));
      dfs(s, j + 1, j + 1);
      temp.pop_back();
    }

    dfs(s, i, j + 1);
  }

  vector<vector<string>> partition(string s) {
    dfs(s, 0, 0);
    return ans;
  }
};

int main() {

  Solution s;

  string test = "aba";

  vector<vector<string>> ans = s.partition(test);

  for (vector<string> x : ans) {
    for (string i : x) {
      cout << i << " ";
    }
    cout << endl;
  }

  return 0;
}