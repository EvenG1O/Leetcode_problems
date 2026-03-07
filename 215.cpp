#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int findKthLargest(vector<int> &nums, int k) {
  priority_queue<int> pq;

  for (int x : nums) {

    pq.push(x);
  }
  k--;
  while (k != 0) {
    pq.pop();
    k--;
  }

  return pq.top();
}

int main() {

  vector<int> nums = {3, 2, 1, 5, 6, 4};

  int ans = findKthLargest(nums, 2);

  cout << ans;

  return 0;
}