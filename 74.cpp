#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target) {

  vector<int> rows;

  for (int i = 0; i < matrix.size(); i++) {

    rows.push_back(matrix[i][0]);
  }

  auto it = lower_bound(rows.begin(), rows.end(), target);

  if (it == rows.end() || *it > target) {
    if (it == rows.begin())
      return false;
    --it;
  }

  int row = it - rows.begin();

  int l = 0, r = matrix[row].size() - 1;

  while (l <= r) {

    int mid = l + (r - l) / 2;

    if (matrix[row][mid] == target)
      return true;

    else if (target > matrix[row][mid])
      l = mid + 1;
    else
      r = mid - 1;
  }

  return false;
}

int main() {

  vector<vector<int>> temp = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};

  bool ans = searchMatrix(temp, 16);

  cout << ans;

  return 0;
}