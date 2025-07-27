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


// Approach 2 ->> Simple Queue traversal, (pushing right first, then left)

class Solution {
public:
    int findBottomLeftValue(TreeNode* root){
        if(!root) return -1;

        queue<TreeNode*> q;
        q.push(root);

        TreeNode* node= root;

        while(!q.empty())
        {
            node= q.front();
            q.pop();
            
            // first push right node
            if(node->right){
                q.push(node->right);
            }

            if(node->left){
                q.push(node->left);
            }
        }
      return node->val;  
    }
};





 // Approach 1 -> Level Wise Traversal
 // TC= O(N)

/*

class Solution {
public:
    int findBottomLeftValue(TreeNode* root){
        if(!root) return -1;

        queue<TreeNode*> q;
        q.push(root);

        int bottomLeft= -1;
        while(!q.empty())
        {
            int n= q.size();
            for(int i=0; i<n; i++)
            {
                TreeNode* node= q.front();
                q.pop();

                if(i== 0){
                   bottomLeft= node->val;
                }
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                
                }
            }
        }
      return bottomLeft;     
    }
};

*/