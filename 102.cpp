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
  vector<vector<int>> levelOrder(TreeNode *root) {
    queue<TreeNode *> q;
    vector<vector<int>> ans;


    if(!root) return ans;
    q.push(root);

    while (!q.empty()) {

      vector<int> temp;
        int size = q.size();
      for (int i = 0; i < size; i++) {
        if(!q.empty())temp.push_back(q.front()->val);
        
        if (q.front()->left)
          q.push(q.front()->left);

        if (q.front()->right)
          q.push(q.front()->right);

        q.pop();
      }

      ans.push_back(temp);
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

  TreeNode *root = new TreeNode(3);

  TreeNode *two = new TreeNode(1);

  TreeNode *three = new TreeNode(2);

  TreeNode *four = new TreeNode(4);

  TreeNode *five = new TreeNode(5);

  root->left = two;
  root->right = three;
  two->left = four;
  four->left = five;

  

  vector<vector<int>> ans = temp.levelOrder(root);

  for (int i = 0; i < ans.size(); i++) {

    for (int x = 0; x < ans[i].size(); x++) {
      cout << ans[i][x] << endl;
    }
    cout << endl;
  }

  return 0;
}