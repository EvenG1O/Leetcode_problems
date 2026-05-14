#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool isGood(vector<int> nums) {
    int base = nums.size();

    unordered_map<int, int> m, original;

    for (int i{}; i < nums.size(); i++) {
      m[nums[i]]++;
    }

    for (int i = 1; i < nums.size(); i++) {
      original[i]++;
    }

    original[nums.size() - 1]++;

    if (original == m)
      return false;

    return true;
  }
};

int main() {
  Solution s;

  vector<int> test = {1, 3, 3, 2};

  bool ans = s.isGood(test);

  if (ans == true)
    cout << "working" << endl;

  return 0;
}