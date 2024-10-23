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

// Intuition ->> Sum of cousins= (Level Sum) - (Sibling sum)


// Approach 1 ->>> 2 times traversing the tree, one for level order sum, other for
// TC= O(2*N)

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        // base case
        if(root== NULL)
        {
            return root;
        } 

        // Step 1 ->> first build up the level order sum of each level in vector...
        vector<int> levelSum;
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty())
        {
            int n= q.size();
            int sum= 0;
            while(n--)
            {
                TreeNode* node= q.front();
                q.pop();
               sum+= node->val;
               if(node->left){
                   q.push(node->left);
               }

               if(node->right){
                  q.push(node->right);
               }
            }
            
            // After completion of each level, insert level sum in vector..
            levelSum.push_back(sum);
        }


        // Step 2 ->> Replace each node value with levelSum - siblingSum
        int i= 1;
        q.push(root);
        root->val= 0;  // root has NO cousin

        while(!q.empty())
        {
            int m= q.size();
            while(m--)
            {
               int siblingSum= 0;
               TreeNode* node= q.front();
               q.pop();

               if(node->left){
                  siblingSum+= node->left->val;
               }

               if(node->right){
                  siblingSum+= node->right->val;
               }

               if(node->left){
                  node->left->val= levelSum[i]- siblingSum;
                  q.push(node->left);
               }

               if(node->right){
                  node->right->val= levelSum[i]- siblingSum;
                  q.push(node->right);
               }
            }
            
            // after completion of each level..
            i++;
        }

    return root;
    }
};