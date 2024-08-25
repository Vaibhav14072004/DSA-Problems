/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


// TC= O(N)

class Solution {
public:
    void solve(TreeNode* root, vector<int> &postorder)
    {
        if(root== NULL){
            return;
        }

        solve(root->left, postorder);
        solve(root->right, postorder);
        postorder.push_back(root->val);
    }


    vector<int> postorderTraversal(TreeNode* root){
        // base case...
        if(root== NULL)
          return {};

         vector<int> postorder;
         solve(root,postorder);
        return postorder; 
    }
};