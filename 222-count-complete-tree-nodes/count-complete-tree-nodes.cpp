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

 // Approach 1 -> BFS
 // TC= O(N)
 // SC= O(N)

class Solution {
public:
    int countNodes(TreeNode* root) {
        // base case
        if(!root){
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);

        int ans= 0;
        while(!q.empty())
        {
            int n= q.size();
            ans+= n;
            while(n--)
            {
                TreeNode* node= q.front();
                q.pop();
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
        }
      return ans;  
    }
};