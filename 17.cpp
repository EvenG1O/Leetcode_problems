#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  std::unordered_map<char, std::string> m = {
      {'1', ""}, 
      {'2', "abc"},  {'3', "def"}, {'4', "ghi"},  {'5', "jkl"}, {'6', "mno"},
      {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}, {'0', " "}};

  vector<char> d;

  vector<string> ans;

  void dfs(string s, int index) {

    if (s.size() == d.size()) {
      ans.push_back(s);
      return;
    }

    if (index >= d.size())
      return;
    char currChar = d[index];
    string currS = m[currChar];

    for (char x : currS) {
      dfs(s + x, index + 1);
    }
  }

  vector<string> letterCombinations(string digits) {

    for (int i{}; i < digits.length(); i++) {

      char temp = digits[i];
      d.push_back(temp);
    }
    string test{};
    dfs(test, 0);

    return ans;
  }
};

int main() {

  Solution s;

  vector<string> ans = s.letterCombinations("23");

  for (string s : ans) {

    cout << s << endl;
  }

  return 0;
}