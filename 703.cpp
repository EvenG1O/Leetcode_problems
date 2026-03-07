#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class KthLargest {
public:
  priority_queue<int, vector<int>, greater<int>> pq;

  int kpos;
  KthLargest(int k, vector<int> &nums) {
    kpos = k;
    
    for (int x : nums) {
      pq.push(x);
      if (pq.size() > k)
        pq.pop();
    }
  }

  int add(int val) {

    pq.push(val);

    if(pq.size() > kpos)pq.pop();

    return pq.top();
  }
};

int main() {

  vector<int> t = {7, 7, 7, 7, 8, 3};

  KthLargest test(4, t);

  test.add(2);  // return 7
  test.add(10); // return 7
  test.add(9);  // return 7
  test.add(9);  // return 8



  return 0;
}