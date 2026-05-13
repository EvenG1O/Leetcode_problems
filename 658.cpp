#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findClosestElements(vector<int> &arr, int k, int x) {
    int l{};
    int r = arr.size() - 1;

    while (r - l >= k) {

      if (abs(x - arr[l]) <= (abs(x -arr[r]) )) {
        r--;
      } else {
        l++;
      }
    }

    return vector<int>(arr.begin() + l, arr.begin() + r + 1);
  }
};

int main() {

  Solution s;

  vector<int> test = {1, 2, 3, 4, 5};

  vector<int> ans = s.findClosestElements(test, 4, 3);

  for (int x : ans) {
    cout << x << endl;
  }

  return 0;
}