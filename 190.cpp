#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  unsigned int reverseBits(unsigned int n) {
    unsigned int ans{};

    for (int i{}; i < 32; i++) {
      int bit = (n >> i) & 1;
      ans = ans | (bit << (31 - i));
    }

    return ans;
  }
};

int main() {
  Solution s;

  unsigned int ans = s.reverseBits(2147483644);

  cout << ans << endl;

  return 0;
}
