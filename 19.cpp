
#include <cmath>
#include <codecvt>
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

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode h(0);
        h.next = head;

        ListNode *curr  = head, *prev = &h;

    
        for(int i =0; i < n; i++) curr = curr->next;

        while (curr) {
            prev = prev->next;
            curr = curr->next;
        }

        prev->next = prev->next->next;

        return  h.next;

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

    ListNode *five = new ListNode(5);

  head->next = two;
  two->next = three;
  three->next = four;
  four->next = five;


  t.PrintList(head);

  t.removeNthFromEnd(head, 2);

  t.PrintList(head);


  return 0;
}