
#include <cmath>
#include <cstddef>
#include <iostream>
#include <ratio>
#include <string>
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

    ListNode *ans = new ListNode();
    ListNode *dummy = ans;
    int c{};

    while (l1 || l2 || c) {

      int t{};

      if (l1) {

        t += l1->val;
        l1 = l1->next;
      }

      if (l2) {

        t += l2->val;
        l2 = l2->next;
      }

      t += c;

      c = t / 10;

      t = t % 10;

      ListNode *n = new ListNode(t);

      ans->next = n;
      ans = ans->next;
    }

    return dummy->next;
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

  ListNode *head = new ListNode(2);

  ListNode *two = new ListNode(4);

  ListNode *three = new ListNode(3);

  ListNode *head2 = new ListNode(5);

  ListNode *two2 = new ListNode(6);

  ListNode *three3 = new ListNode(4);

  head->next = two;
  two->next = three;

  head2->next = two2;

  two2->next = three;
  // t.PrintList(head);

  ListNode *ans = t.addTwoNumbers(head, head2);

  t.PrintList(ans);

  return 0;
}