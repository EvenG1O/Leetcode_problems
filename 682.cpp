#include <cctype>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int calPoints(vector<string> &operations) {

    int ans{};
    int one{};
    int two{};
    stack<int> s;

    for (int i{}; i < operations.size(); i++) {
      if (operations[i].size() > 1 || isdigit(operations[i][0])) {
        s.push(stoi(operations[i]));

      } else {
        if (operations[i][0] == 'C') {

          s.pop();
        } else if (operations[i][0] == 'D') {
          s.push(s.top() * 2);
        } else if (operations[i][0] == '+') {

          one = s.top();
          s.pop();
          two = s.top();
          s.push(one);
          s.push(one + two);
        }
      }
    }

    while (!s.empty()) {
      ans += s.top();
      s.pop();
    }

    return ans;
  }
};

int main() {

  Solution s;

  vector<string> test = {"5", "-2", "4", "C", "D", "9", "+", "+"};

  int ans = s.calPoints(test);

  cout << ans << endl;

  return 0;
}