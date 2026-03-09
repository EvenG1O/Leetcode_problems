#include <cstddef>
#include <iostream>
#include <type_traits>
#include <utility>
#include <vector>


using  namespace  std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr),right(nullptr) {} 
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};


class Solution{

    public: 
    TreeNode *invertTree(TreeNode  *root){

        if(root == nullptr) return nullptr;

        swap(root->left,root->right);

        invertTree(root->left);
        invertTree(root->right);

        return root;

    };

    TreeNode *PrintTree(TreeNode *root)
    {
        if(root == nullptr) return nullptr;

        cout<<root->val<<endl;

        PrintTree(root->left);
        PrintTree(root->right);
        
        return root;
    }
};





int main()
{

    Solution temp;

    TreeNode *root = new TreeNode(0);

    TreeNode *two = new TreeNode(3);

    TreeNode *three = new TreeNode(7);


    root->left = two;

    root->right = three;

    temp.PrintTree(root);

    temp.invertTree(root);

    cout<<endl;

    temp.PrintTree(root);

    









  


    return 0;
}