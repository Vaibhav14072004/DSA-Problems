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

 // TC= O(N)
 // SC= O(log N)

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root== NULL)
        {
            return {};
        }

        queue<TreeNode*> q;
        q.push(root);
        
        vector<vector<int>> ans;
        while(!q.empty())
        {
            int n= q.size();
            vector<int> levelOrder;
              
            while(n--)
            {
               TreeNode* node= q.front();
               q.pop();
               levelOrder.push_back(node->val);

               if(node->left)
               {
                   q.push(node->left);
               }
               if(node->right)
               {
                  q.push(node->right);
               }
            }
            ans.push_back(levelOrder);
        }
        return ans;
    }
};