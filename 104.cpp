#include <algorithm>
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

    int maxDepth(TreeNode  *root){
        

        if(root == nullptr) return 0;
        

        int l = maxDepth(root->left);
        int r = maxDepth(root->right);

        return max(l + 1 ,r + 1 );


        
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

    TreeNode *four = new TreeNode(73);


    root->left = two;

    root->right = three;

    three->right = four;

    temp.PrintTree(root);

    int ans = temp.maxDepth(root);

    cout<<ans;


    









  


    return 0;
}