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

// Approach 2 -> USing DFS for level wise traversal
// TC= O(N)
// SC= O(log n)


class Solution {
 public:
    void solve(TreeNode* root, int level, vector<int> &ans)
    {
        if(root== NULL)
          return;

        // if this level is being visited for the first time.. 
        if(level== ans.size())
        {
           ans.push_back(root->val);
        }
        else
        {
            ans[level]= max(ans[level], root->val);
        }

        solve(root->left, level+1, ans);
        solve(root->right, level+1, ans);
    }

    vector<int> largestValues(TreeNode* root){
         if(root== NULL)
           return {};

         vector<int> ans;
         solve(root,0,ans);
         return ans;
    }
};







// Approach 1 -> Using BFS
// TC= O(N)
// SC= O(N)

/*

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root== NULL)
          return {};

        queue<TreeNode*> q;
        q.push(root);

        vector<int> ans;

        while(!q.empty())
        {
            int n= q.size();
            int maxi= INT_MIN;
            while(n--)
            {
                TreeNode* node= q.front();
                q.pop();
                maxi= max(maxi,node->val);

                if(node->left){
                    q.push(node->left);
                }

                if(node->right){
                    q.push(node->right);
                }
            }

            ans.push_back(maxi);
        }
       return ans; 
    }
};

*/