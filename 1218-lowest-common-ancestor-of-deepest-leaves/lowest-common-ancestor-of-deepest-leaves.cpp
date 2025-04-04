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


// First find maximum depth of tree, then find LCA of nodes at maximum depth 

 // Approach 1 ->> 2 pass solution
 // TC= O(2* N)

class Solution {
public:
    TreeNode* LCA(TreeNode* root, int &maxDepth,unordered_map<int,int> &mp)
    {
        // base case
        if(root== NULL|| mp[root->val]== maxDepth){
            return root;
        }
        
        TreeNode* left= LCA(root->left, maxDepth, mp);
        TreeNode* right= LCA(root->right,maxDepth,mp);

        if(left && right){
            return root;
        }

        else if(left){
           return left;
        }
        else{
            return right;
        }
    }

    void findMaxDepth(TreeNode* root, int depth, int &maxDepth,unordered_map<int,int> &mp)
    {
       if(root== NULL){
          return;
       }

       mp[root->val]= depth;
       maxDepth= max(maxDepth, depth);

       findMaxDepth(root->left, depth+1,maxDepth,mp);
       findMaxDepth(root->right, depth+1,maxDepth,mp);
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root== NULL){
            return NULL;
        }

        int maxDepth= 0;
        unordered_map<int,int> mp;
        findMaxDepth(root,0,maxDepth,mp);

        return LCA(root,maxDepth,mp);
    }
};