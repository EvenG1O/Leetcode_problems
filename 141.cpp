// DO this problem  with a hash table  it  should be  pretty  easy  sotre the
// pointer  in a hash table  look it up  every time  u check  a new  node  if we
// have seen it before return  true else false

// THis  one is solved  using  2  pointers  ez  u got  this

#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>

#include <map>

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
  bool hasCycle(ListNode *head) {

    unordered_set<ListNode *> m;

    while (head) {

      if (m.count(head))
        return true;
      m.insert(head);

      head = head->next;
    }

    return false;
  }

  void PrintList(ListNode *head) {
    ListNode *temp = head;
    while (temp) {

      cout << temp->val << endl;
      temp = temp->next;
    }
  }
};

int main() {

  Solution t;

  ListNode *head = new ListNode(1);

  ListNode *two = new ListNode(2);

  head->next = two;
  two->next = head;

  bool ans = t.hasCycle(head);

  if (ans)
    cout << "Positive";

  return 0;
}