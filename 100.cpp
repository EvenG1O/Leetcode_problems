#include <iostream>
#include <queue>

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
  queue<TreeNode *> l, r;

  bool isSameTree(TreeNode *p, TreeNode *q) {

    if(!q && !p) return true;
    if (!q || !p)
      return false;

    l.push(p);
    r.push(q);

    while (!l.empty() && !r.empty()) {

      if (l.front()->val != r.front()->val)
        return false;

      if (l.front()->left)
        l.push(l.front()->left);
      if (r.front()->left)
        r.push(r.front()->left);
      if (r.size() != l.size())
        return false;

      if (l.front()->right)
        l.push(l.front()->right);
      if (r.front()->right)
        r.push(r.front()->right);
      if (r.size() != l.size())
        return false;

      l.pop();
      r.pop();
    }
    return true;
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

  root->left = two;

  three->left = four;

  temp.PrintTree(root);

  bool ans = temp.isSameTree(root,three);

  if(ans)cout<<"Working";


  return 0;
}