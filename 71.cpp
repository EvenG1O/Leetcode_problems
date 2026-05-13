#include <iostream>
#include <stack>
#include <string>
#include <system_error>

using namespace std;

class Solution {
public:
  string ans;

  string simplifyPath(string path) {

    stack<string> sta;
    string currDir;

    string prevDir = "..";

    string ans;

    for (char c : path) {

      if (c == '/') {
        if (currDir == prevDir) {
          if (!sta.empty())
            sta.pop();
        } else if (currDir != "." && !currDir.empty()) {
          sta.push(currDir);
        }
        currDir = "";

      } else {
        currDir += c;
      }
    }

    if (currDir == prevDir) {
      if (!sta.empty())
        sta.pop();
    } else if (currDir != "." && !currDir.empty()) {
      sta.push(currDir);
    }

    while (!sta.empty()) {

      ans = "/" + sta.top() + ans;
      sta.pop();
    }

    return ans.empty() ?  "/" : ans;
  }
};

int main() {

  string test = "/.../a/../b/c/../d/./";

  Solution s;

  string ans = s.simplifyPath(test);

  cout << ans << endl;

  return 0;
}
