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

// Approach 1 -> Using DFS
// TC= O(N)

// SC= O(Height of tree) bcoz of recursion stack space
// SC= O(log n) in balanced tree, O(n) for skewed tree


class Solution {
public:
    void DFS(TreeNode* root,int level,vector<int> &vec)
    {
        if(!root) return;

        if(vec.size() <= level){
            vec.push_back(root->val);
        }
        
        // first call for root->right, then after root->left
        if(root->right){
            DFS(root->right,level+1,vec);
        }
        if(root->left){
            DFS(root->left,level+1,vec);
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> vec;
        DFS(root,0,vec);
        return vec;
    }
};