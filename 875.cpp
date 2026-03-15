#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

long long minTime(int mid, vector<int> &piles) {
  long long  amount{};

  for (int x : piles) {

    amount += ((long long)x + mid - 1) / mid;
  }

  return amount;
}

int minEatingSpeed(vector<int> &piles, int h) {

  int max = piles.back();
  int ans = piles.back();



  int l = 1;
  int r = *max_element(piles.begin(), piles.end());

  while (l <= r) {
    int mid = l + (r - l) / 2;

    if (minTime(mid, piles) <= h) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  return ans;
}

int main() {

  vector<int> temp = {30, 11, 23, 4, 20};

  int ans = minEatingSpeed(temp, 6);

  cout << ans;

  return 0;
}