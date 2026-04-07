#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <unordered_map>
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
  int preOrdIndex{};
  unordered_map<int, int> ind;

  TreeNode *dfs(vector<int> &preorder, int l, int r) {

    if (l > r)
      return nullptr;

    int val = preorder[preOrdIndex++];
    TreeNode *temp = new  TreeNode(val);
    int mid = ind[val];

    temp->left = dfs(preorder, l,mid - 1);
    temp->right = dfs(preorder, mid + 1, r);

    return temp;

  }

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    for (int i = 0; i < inorder.size(); ++i) {
      ind[inorder[i]] = i;
    }
    return dfs(preorder,0,inorder.size() - 1);
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


  vector<int>inorder = {9,3,15,20,7};
  vector<int>preorder = {3,9,20,15,7};

    TreeNode *ans = temp.buildTree(preorder, inorder);

    if(ans)cout<<"working"<<endl;
    temp.PrintTree(ans);


  return 0;
}