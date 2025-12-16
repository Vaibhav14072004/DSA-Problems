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

// Approach 1 -> DFS
// TC= O(N)

class Solution{
  public:
    bool DFS(TreeNode* root, TreeNode* mini, TreeNode* maxi)
    {
        if(!root) return true;
        if(mini != NULL && root->val <= mini->val) return false;
        if(maxi != NULL && root->val >= maxi->val) return false;

        return DFS(root->left,mini,root) && DFS(root->right,root,maxi);
    }

    bool isValidBST(TreeNode* root)
    {
       if(!root) return true;
       TreeNode* mini= NULL;
       TreeNode* maxi= NULL;
       return DFS(root,mini,maxi);
    }
};

