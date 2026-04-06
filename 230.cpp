#include <functional>
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
  priority_queue<int, vector<int>, greater<int>> pq;

  void traverse(TreeNode *root) {
    if (!root)
      return;

    pq.push(root->val);

    traverse(root->left);
    traverse(root->right);
    return;
  }

  int kthSmallest(TreeNode *root, int k) {

    traverse(root);

    for (int i = 1; i < k; i++) {
      pq.pop();
    }
    return pq.top();
  }

  TreeNode *PrintTree(TreeNode *root) {
    if (root == nullptr)
      return nullptr;
    PrintTree(root->left);
    PrintTree(root->right);
    return root;
  }
};

int main() {

  Solution temp;

  TreeNode *root = new TreeNode(3);

  TreeNode *two = new TreeNode(1);

  TreeNode *three = new TreeNode(4);

  TreeNode *four = new TreeNode(2);

  root->left = two;

  root->right = three;

  two->right = four;

  int ans = temp.kthSmallest(root, 1);

  cout << ans;

  return 0;
}