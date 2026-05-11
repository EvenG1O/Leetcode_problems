#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> ans;

  unordered_map<char, int> getFreq(string s) {
    unordered_map<char, int> map;

    for (char c : s) {
      map[c] += 1;
    }

    return map;
  }

  vector<int> findAnagrams(string s, string p) {

    unordered_map<char, int> map = getFreq(p);
    unordered_map<char, int> current;

    for (int i{}; i < s.length(); i++) {

      current[s[i]]++;

      if (i >= p.length()) {
        char leftc = s[i - p.length()];
        current[leftc]--;

        if (current[leftc] == 0) {
          current.erase(leftc);
        }
      }

      if (map == current)
        ans.push_back(i - p.length() + 1);
    }

    return ans;
  }
};

int main() {

  Solution sol;

  string s = "cbaebabacd", p = "abc";

  vector<int> ans = sol.findAnagrams(s, p);

  for (int x : ans) {
    cout << x << endl;
  }

  return 0;
}