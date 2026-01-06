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

// Approach 1 -> Using BFS
 // TC= O(N)

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        
        queue<TreeNode*> q;
        q.push(root);

        int maxi= INT_MIN;
        int level= 0, ans= 0;

        while(!q.empty())
        {
            int n= q.size();
            int sum= 0;
            level++;

            while(n--)
            {
                TreeNode* node= q.front();
                q.pop();
                sum+= node->val;
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
            
            if(maxi < sum)
            {
                maxi= sum;
                ans= level;
            }
        }
    return ans;
    }
};