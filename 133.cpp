#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }

  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }

  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {

public:
  unordered_map<int, bool> m;
  unordered_map<int, Node *> add;
  queue<Node *> q;

  Node *head;

  Node *cloneGraph(Node *node) {
    if (node == nullptr)
      return nullptr;
    q.push(node);

    while (!q.empty()) {

      if (m[q.front()->val] == true) {
        q.pop();
        continue;
      };

      vector<Node *> copy;

      Node *temp;
      if (add[q.front()->val] == nullptr) {
        temp = new Node(q.front()->val);
        add[q.front()->val] = temp;
      } else
        temp = add[q.front()->val];

      if (temp->val == 1)
        head = temp;

      for (int i{}; i < q.front()->neighbors.size(); i++) {

        if (add[q.front()->neighbors[i]->val] == nullptr) {
          Node *newNode = new Node(q.front()->neighbors[i]->val);
          add[q.front()->neighbors[i]->val] = newNode;
        }

        copy.push_back(add[q.front()->neighbors[i]->val]);
        if (m[q.front()->neighbors[i]->val] == false)
          q.push(q.front()->neighbors[i]);
      }

      temp->neighbors = copy;
      m[temp->val] = true;
      q.pop();
    }
    return head;
  }
};

int main() {

  Solution s;

  Node *one = new Node(1);
  Node *two = new Node(2);
  Node *three = new Node(3);
  Node *four = new Node(4);

  one->neighbors = {two, four};
  two->neighbors = {one, three};
  three->neighbors = {two, four};
  four->neighbors = {one, three};

  Node *ans = s.cloneGraph(one);

  queue<Node *> q;
  unordered_set<int> visited;

  q.push(ans);
  visited.insert(ans->val);

  while (!q.empty()) {

    cout << q.front()->val << endl;

    for (int i{}; i < q.front()->neighbors.size(); i++) {
      if (visited.find(q.front()->neighbors[i]->val) == visited.end()) {
        visited.insert(q.front()->neighbors[i]->val);
        q.push(q.front()->neighbors[i]);
      }
    }
    q.pop();
  }

  return 0;
}