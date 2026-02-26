#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

bool isPossible(vector<int> &target) {
  priority_queue<long long, vector<long long>> maxHeap;

  long long  sum = 0;
  for (long long x : target) {
    maxHeap.push(x);
    sum += x;
  }

  

  while (maxHeap.top() > 1) {

    long long temp = maxHeap.top();
    maxHeap.pop();

    long long tempsum = sum - temp;

    if (tempsum <= 0 || tempsum >= temp)
      return false;

    long long prev = temp % tempsum;

    if (prev == 0)
      return (tempsum == 1);

    sum = tempsum + prev;

    maxHeap.push(prev);
  }

  return true;

}

int main() {
  vector<int> target = {9,3,5};

  bool ans = isPossible(target);

  if (ans)
    cout << "working";
  else
    cout << "Not  working";

  return 0;
}