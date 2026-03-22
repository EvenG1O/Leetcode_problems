#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
  Node *copyRandomList(Node *head) {

    if (!head)
      return nullptr;

    unordered_map<Node *, Node *> m;
    Node *curr = head;

    while (curr) {
      m[curr] = new Node(curr->val);
      curr = curr->next;
    }

    curr = head;

    while (curr) {


      if (curr->next)
        m[curr]->next = m[curr->next];
      if (curr->random)
        m[curr]->random = m[curr->random];
      curr = curr->next;
    }

    return m[head];
  }

  void printList(Node *head) {

    Node *temp = head;

    while (temp) {
      cout << temp->val << endl;
      temp = temp->next;
    }
  }
};

int main() {

  Node head(1);
  Node two(2);
  Node three(3);
  Node four(4);

  head.next = &two;
  two.next = &three;
  three.next = &four;

  Solution ans;

  ans.printList(&head);

  Node *anss = ans.copyRandomList(&head);

  ans.printList(anss);

  return 0;
}