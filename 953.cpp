#include <ios>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {

public:
  bool stringsSame(string s, string s2, unordered_map<char, int> &m) {
    int index1{}, index2{};

    while (s.size() > index1 && s2.size() > index2) {

      if (m[s[index1]] > m[s2[index2]])
        return false;
      if (m[s[index1]] < m[s2[index2]])
        return true;

      index1++;
      index2++;
    }

  

    return s.size() <= s2.size();
  }

  bool isAlienSorted(vector<string> &words, string order) {
    int l{};
    int r = 1;
    unordered_map<char, int> m;

    for (int i{}; i < order.length(); i++) {
      m[order[i]] = i;
    }

    while (words.size() > r) {
      if (stringsSame(words[l], words[r], m) == false)
        return false;
      l++;
      r++;
    }

    return true;
  }
};

int main() {

  Solution s;
  vector<string> words = {"apple", "app"};

  string order = "abcdefghijklmnopqrstuvwxyz";

  bool ans = s.isAlienSorted(words, order);

  cout << boolalpha << ans;

  return 0;
}