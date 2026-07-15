
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    set<int> s;
    set<int> s2;
    vector<int> ans;

    for (int x : nums1)
      s.insert(x);

    for (int x : nums2) {

      if (s.count(x) && !s2.count(x)) {
        ans.push_back(x);
        s2.insert(x);
      }
    }

    return ans;
  }
};

int main() {
  Solution s;

  vector<int> test = {1, 2, 2, 1};
  vector<int> test2 = {2, 2};

  vector<int> ans = s.intersection(test, test2);

  for (int x : ans) {

    cout << x << endl;
  }

  return 0;
}