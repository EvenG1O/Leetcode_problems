#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &nums, int target) {

  int l = 0;

  int r = nums.size() - 1;

  while (l <= r) {

    int mid = l + (r - l) / 2;

    if (nums[mid] == target) {
      return mid;
    }

    else if (nums[mid] < target)
      l = mid + 1;

    else
      r = mid - 1;
  }

  return -1;
}

int main() {

  vector<int> temp = {-1, 0, 3, 5, 9, 12};

  int ans = search(temp, 9);

  cout << ans;

  return 0;
}