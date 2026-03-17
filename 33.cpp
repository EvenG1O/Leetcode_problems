#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &nums, int target) {

  int left{};
  int right = nums.size() - 1;

  int ans{};

  if (nums[left] == target)
    return left;

  while (left <= right) {

    int mid = left + (right - left) / 2;

    if (nums[mid] == target)
      return mid;

    if (nums[mid] <= nums[right]) {
      if (target <= nums[right] && nums[mid] <= target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }

    } else {
      if (target >= nums[left] && nums[mid] >= target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
  }

  return -1;
}

int main() {

  vector<int> nums = {4, 5, 6, 7, 8, 1, 2, 3};

  int ans = search(nums, 8);

  cout << ans;

  return 0;
}