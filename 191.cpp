
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

  int hammingWeight(int n)
  {
    int ans{};

    while (n) {
        
        ans += n % 2;  
        n = n >> 1;
    
    }

    return ans ;
  }

};

int main() {

    Solution s;

    int ans = s.hammingWeight(11);

    cout<<ans<<endl;


  return 0;
}