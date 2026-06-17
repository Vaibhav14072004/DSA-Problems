/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */



// Brute Force Approach
// Storing all possible ancestors for both nodes and then comparing it 

// TC= O(N)
// SC= O(H) where H -> height of binary tree

bool getPath(TreeNode* root,TreeNode* targetNode, vector<TreeNode*> &path)
{
    if(root== NULL) return false;

    path.push_back(root);
    
    if(root==  targetNode) return true;

    if(getPath(root->left,targetNode,path) || getPath(root->right,targetNode,path)){
        return true;
    }

    // backtarcking..
    path.pop_back();
    return false;
}

class Solution{
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root== NULL) return NULL;  
        
        vector<TreeNode*> path1,path2;
        getPath(root,p,path1);
        getPath(root,q,path2);

        int i=0;
        while(i< path1.size() && i < path2.size() && path1[i]== path2[i])
        {
            i++;
        }
    return path1[i-1]; 
    }
};





// Optimized Approach ->> Recursion..
// TC= O(N)

/*

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root== NULL) return NULL;
        
        if(root== p || root== q) return root;

        TreeNode* leftN= lowestCommonAncestor(root->left,p,q);
        TreeNode* rightN= lowestCommonAncestor(root->right,p,q);

        if(leftN != NULL && rightN != NULL)
        {
            return root;
        }
        else if(leftN != NULL)
        {
            return leftN;
        }
        return rightN;
    }
};

*/