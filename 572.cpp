#include <cstddef>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {

public:
  vector<TreeNode *> t;
  bool isSubtree(TreeNode *root, TreeNode *subroot) {

    findnode(root, subroot);
    if (!root && !subroot)
      return true;
    if (!root || !subroot)
      return false;

    if (t.empty())
      return false;

    while (!t.empty()) {

      TreeNode *temp = subroot;
      if (isSub(t.back(), temp))
        return true;
      t.pop_back();
    }

    return false;
  }

  bool isSub(TreeNode *root, TreeNode *subroot) {

    queue<TreeNode *> qroot, qsubroot;
    qroot.push(root);
    qsubroot.push(subroot);
    while (!qroot.empty() && !qsubroot.empty()) {

      if (qroot.front()->val != qsubroot.front()->val) {
        return false;
      }
      if ((qroot.front()->left != nullptr) !=
          (qsubroot.front()->left != nullptr))
        return false;
      if ((qroot.front()->right != nullptr) !=
          (qsubroot.front()->right != nullptr))
        return false;
      if (qroot.front()->left)
        qroot.push(qroot.front()->left);
      if (qroot.front()->right)
        qroot.push(qroot.front()->right);

      if (qsubroot.front()->left)
        qsubroot.push(qsubroot.front()->left);
      if (qsubroot.front()->right)
        qsubroot.push(qsubroot.front()->right);

      qroot.pop();
      qsubroot.pop();
    }

    return true;
  }

  void findnode(TreeNode *root, TreeNode *isSubtree) {
    if (!root)
      return;
    int top = isSubtree->val;
    if (root->val == top) {
      t.push_back(root);
    }
    if (root->left)
      findnode(root->left, isSubtree);
    if (root->right)
      findnode(root->right, isSubtree);
  }

  TreeNode *PrintTree(TreeNode *root) {
    if (root == nullptr)
      return nullptr;

    cout << root->val << endl;

    PrintTree(root->left);
    PrintTree(root->right);

    return root;
  }
};

int main() {

  Solution temp;

  TreeNode *root = new TreeNode(0);

  TreeNode *two = new TreeNode(3);

  TreeNode *three = new TreeNode(0);

  TreeNode *four = new TreeNode(3);

  TreeNode *five = new TreeNode(7);

  root->left = two;
  three->left = four;
  bool ans = temp.isSubtree(root, three);

  if (ans == true)
    cout << "working";

  return 0;
}