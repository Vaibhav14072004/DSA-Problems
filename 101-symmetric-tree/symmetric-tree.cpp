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

// Approach 2 -> BFS 
// TC= O(N)
// SC= O(N)

class Solution{
 public:
    bool isSymmetric(TreeNode* root) {
        if(root== NULL)
          return true;
        
        if(root->left== NULL && root->right== NULL){
            return true;
        }
        
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root->left,root->right});

        while(!q.empty())
        {
            TreeNode* leftNode= q.front().first;
            TreeNode* rightNode= q.front().second;
            q.pop();

            if(leftNode== NULL && rightNode== NULL){
                continue;
            }
            
            // if any one node is NULL but other is NOT, return false
            if(leftNode== NULL || rightNode== NULL){
               return false;
            }
            
            if(leftNode->val != rightNode->val){
                return false;
            }

            // we have to match (leftNode->left) to (rightNode->right) and vice versa for mirror symmetry
            q.push({leftNode->left, rightNode->right});

            q.push({leftNode->right, rightNode->left});
        }
       return true; 
    }
};





 // Approach 1 -> Using DFS
 // TC= O(N)
 // SC= O[log 2 (N)] ->> Recursive stack space

/*

class Solution {
public:
    bool solve(TreeNode* rootLeft, TreeNode* rootRight)
    {
        if(rootLeft== NULL && rootRight== NULL){
            return true;
        }

        if(rootLeft== NULL || rootRight== NULL){
            return false;
        }

        if(rootLeft->val != rootRight->val){
            return false;
        }
        
        // left child of root->left is compared with right child of root->right 
        bool case1= solve(rootLeft->left, rootRight->right);

        // right child of root->left is compared with left child of root->left
        bool case2= solve(rootLeft->right, rootRight->left);

        return case1 && case2;
    }


    bool isSymmetric(TreeNode* root) {
        if(root== NULL)
          return true;
        
        return solve(root->left,root->right);
    }
};

*/