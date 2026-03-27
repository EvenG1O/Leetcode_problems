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

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *ans = root;

        while (ans) {
        
            if(ans->val > p->val && ans->val > q->val) 
            if(ans->right) ans = ans->left;
            else return ans;
            else if (ans->val < p->val && ans->val < q->val)
            if(ans->left)ans = ans->right;
            else return ans;
            else return  ans;
        }

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

  TreeNode *root = new TreeNode(3);

  TreeNode *two = new TreeNode(1);

  TreeNode *three = new TreeNode(2);

  TreeNode *four = new TreeNode(4);

  TreeNode *five = new TreeNode(5);

  root->left = two;
two->left = three;
root->right = four;
four->left = five;

  TreeNode *ans = temp.lowestCommonAncestor(root,four, five);

  cout<<ans->val;
  



  return 0;
}