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
  vector<int> rightSideView(TreeNode *root) {

    queue<TreeNode *> q;
    vector<int> ans;
    if(!root) return ans;

    q.push(root);

   

    while (!q.empty()) {

    int size = q.size();
      for (int i{}; i < size; i++) {
        if (q.front()->left)
          q.push(q.front()->left);
        if (q.front()->right)
          q.push(q.front()->right);

        if (i == size -1) ans.push_back(q.front()->val);
        q.pop();
      }
    }

    return ans;
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

  //   temp.PrintTree(root);

  // cout<<endl;

  // temp.PrintTree(root);

  vector<int> ans = temp.rightSideView(root);

  for (int x : ans) {
    cout << x << endl;
  }

  return 0;
}