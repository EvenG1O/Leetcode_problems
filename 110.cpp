#include <algorithm>
#include <cstddef>
#include <cstdlib>
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

    int numss(TreeNode *root){
        
        if(root == nullptr) return 0;

        int left = numss(root->left);
        int right = numss(root->right);

        int balance = abs(left-right);
        if(balance > 1 || left == -1 || right == -1){
            return -1;
        }

        return 1 + max(left,right);




    }



    bool isBalanced(TreeNode *root)
    {
        if(root == nullptr) return true;
        
        int temp = numss(root);
        if(temp == -1) return false;
        return  true;
        





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

  root->right = three;


  temp.PrintTree(root);


  bool ans = temp.isBalanced(root);

  if(ans) cout<<"working";

  


  return 0;
}