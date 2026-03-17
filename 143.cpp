
#include <cmath>
#include <cstddef>
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
  ListNode *reverseList(ListNode *head) {

    ListNode *curr = head;
    ListNode *prev = NULL;

    while (curr) {
      ListNode *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    return prev;
  }

  void reorderList(ListNode *head) {

    if (!head || !head->next)
      return;

    ListNode *fast = head;
    ListNode *slow = head;

    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }

    ListNode *second = reverseList(slow->next);
    slow->next = nullptr;

    ListNode *first = head;

    while (second) {
      ListNode *temp1 = first->next;
      ListNode *temp2 = second->next;
      first->next = second;
      second->next = temp1;
      first = temp1;
      second = temp2;
    }
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

  ListNode *three = new ListNode(3);

  ListNode *four = new ListNode(4);

  head->next = two;
  two->next = three;
  three->next = four;

  t.reorderList(head);

  t.PrintList(head);

  return 0;
}