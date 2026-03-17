#include <cmath>
#include <iostream>
#include <vector>

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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *currr = new ListNode();
    ListNode *curr = currr;

    while (list1 && list2) {

      if (list1->val <= list2->val) {

        curr->next = list1;
        list1 = list1->next;

      } else {
        curr->next = list2;

        list2 = list2->next;
      }
      curr = curr->next;
    }

    if (list1)
      curr->next = list1;
    if (list2)
      curr->next = list2;
    return currr->next;
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

  ListNode *head2 = new ListNode(3);

  ListNode *two2 = new ListNode(4);

  head2->next = two2;

  ListNode *ans = t.mergeTwoLists(head, head2);

  t.PrintList(ans);

  return 0;
}