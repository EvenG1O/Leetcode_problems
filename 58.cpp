#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int lengthOfLastWord(string s) {

    int slow{};
    int fast{};
    int prevfast{};

    string currentLastWord{};

    bool flag{};

    for (fast; fast < s.length(); fast++) {

      if (s[fast] != ' ') {
        if (!flag) {
          flag = true;
          slow = fast;
        }
        prevfast = fast;
      } else {
        flag = false;
      }
    }

    return prevfast + 1 - slow;
  }
};

int main() {

  Solution s;

  int ans = s.lengthOfLastWord("Hello World");

  cout << ans << endl;

  return 0;
}