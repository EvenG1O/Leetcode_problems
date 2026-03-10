#include <algorithm>
#include <iostream>


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
  int maxDiameter = 0;

  int maxDepth(TreeNode *root) {

    if (root == nullptr)
      return 0;

    int l = maxDepth(root->left);
    int r = maxDepth(root->right);

    maxDiameter = max(maxDiameter, l + r);

    return max(l, r) + 1;
  }

  int diamaterOFBinaryTree(TreeNode *root) {

    maxDepth(root);

    return maxDiameter;
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

  TreeNode *three = new TreeNode(7);

  TreeNode *four = new TreeNode(73);

  root->left = two;

  temp.PrintTree(root);

  int ans = temp.diamaterOFBinaryTree(root);

  cout << ans;

  return 0;
}