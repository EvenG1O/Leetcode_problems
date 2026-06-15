
#include <vector>

using namespace std;

class Solution {
public:
  void merge(vector<int> &nums, int m, vector<int> &nums2, int n) {

    vector<int> ans;

    int l{m - 1};
    int r{n - 1};
    int currentIndex = m + n - 1;

    while (l >= 0 && r >= 0) {
      if (nums[l] >= nums2[r]) {
        nums[currentIndex] = nums[l];
        l--;
      } else {
        nums[currentIndex] = nums2[r];
        r--;
      }
      currentIndex--;
    }

    while (r >= 0) {
      nums[currentIndex] = nums2[r];
      currentIndex--;
      r--;
    }
  }
};

int main() {

  Solution s;
  vector<int> nums = {1, 2, 3, 0, 0, 0}, nums2 = {2, 5, 6};

  s.merge(nums, 3, nums2, 3);

  return 0;
}