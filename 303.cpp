#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
  vector<int> arr;

  NumArray(vector<int> &nums) { arr = nums; }

  int sumRange(int left, int right) {
    int currentSum{};

    for (left; left <= right; left++) {
      currentSum += arr[left];
    }
    return currentSum;
  }
};

int main() {
  vector<int> test = {-2, 0, 3, -5, 2, -1};

  NumArray s(test);

  int ans = s.sumRange(0, 2);

  cout << ans << endl;

  return 0;
}