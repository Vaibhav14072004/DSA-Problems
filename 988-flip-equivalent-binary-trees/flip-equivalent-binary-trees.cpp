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


// NOTE ->> Level order traversal will Not give correct ans bcoz we can swap any node of left subtree with right subtree,... it does not mean that only nodes at same level can be swapped, nodes at any level can be swapped

// Recursive Approach 

// TC= O(4*N) ---> O(N)
// SC= O(Max depth of tree) ---> O(Log n) -->> used in recursive stack

class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // base case
        if(root1== NULL && root2== NULL)
        {
            return true;
        }
        
        // if one subtree has less nodes than other.. return false
        if(root1 == NULL || root2== NULL)
        {
            return false;
        }
        
        // initial roots should have same values..
        if(root1->val != root2->val)
        {
            return false;
        }
        
        // if flip NOT done, compare left with left, right with right subtree..
        bool withoutFlip= flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right);
        
        // if flip done, compare right with left and left with right subtree..
        bool flipDone= flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);

        return withoutFlip || flipDone;
    }
};