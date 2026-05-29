#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  unordered_map<int, int> m;

  int majorityElement(vector<int> &nums) {

    int ans{};

    for (int x : nums) {
      m[x]++;

      if ((nums.size() / 2) < m[x]) {
        ans = x;
        break;
      }
    }

    return ans;
  }
};

int main() {
  Solution s;

  vector<int> test = {3, 2, 3};

  int ans = s.majorityElement(test);

  cout << ans << endl;

  return 0;
}
