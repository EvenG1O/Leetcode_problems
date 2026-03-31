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
  int goodNode(TreeNode *root, int maxVal) {

    if (!root)
      return maxVal;

    int res{};

    if (root->val >= maxVal)
      res += 1;

    maxVal = max(maxVal,root->val);
    if (root->left)
      res += goodNode(root->left, maxVal);
    if (root->right)
      res += goodNode(root->right, maxVal);

    return res;
  }

  int goodNodes(TreeNode *root) {

    int ans = goodNode(root, root->val);

    return  ans;




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

  TreeNode *four = new TreeNode(5);

  TreeNode *five = new TreeNode(5);

  root->left = two;

  root->right = three;

  three->left = four;

  four->left = five;

  //temp.PrintTree(root);

  int ans = temp.goodNodes(root);
cout<<ans;


  return 0;
}