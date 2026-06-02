#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {

    int len = strs[0].size();

    if (len == 0)
      return strs[0];

    char currentc;
    string ans{""};

    for (int i{}; i < len; i++) {
      int counter = strs.size() - 1;
      if (strs[counter].size() < i)
        return ans;
      currentc = strs[counter][i];

      while (counter--) {
        if (strs[counter].size() <= i)
          return ans;
        if (currentc != strs[counter][i])
          return ans;
      }

      ans += currentc;
    }

    return ans;
  }
};

int main() {

  Solution s;

  vector<string> test = {"flower", "flow", "flight"};

  string ans = s.longestCommonPrefix(test);

  cout << ans << endl;

  return 0;
}