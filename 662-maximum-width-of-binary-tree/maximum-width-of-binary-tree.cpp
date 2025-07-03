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

 // Approach 2 ->> BFS
 // TC=O(N)

class Solution{
  public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        // {node, idx}
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});

        int maxWidth= 0;

        // If root-> idx, then left child -> 2*idx+1, right child-> 2*idx+2
        while(!q.empty())
        {
            long long val= q.front().second;
            int n= q.size();
            
            int first,last;
            for(int i=0; i<n; i++)
            {
                TreeNode* curr= q.front().first;

                // to avoid overflow, minus with val, to convert it from 0 to ...
                long long value= (q.front().second)- val;
                q.pop();

                if(i== 0){
                    first= value;
                } 
                if(i== n-1){
                    last= value;
                }

                if(curr->left)
                {
                    q.push({curr->left,2*value+1});
                }
                if(curr->right)
                {
                    q.push({curr->right,2*value+2});
                }
            }
            maxWidth= max(maxWidth,(int) last-first+1);
        }
    return maxWidth;
    }
};






/* ---- Giving MLE (due to overflow) -----

class Solution {
public:
    typedef unsigned long long ll;

    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        // {node, idx}
        queue<pair<TreeNode*,ll>> q;
        q.push({root,0});

        // If root-> idx, then left child -> 2*idx+1, right child-> 2*idx+2
        ll maxWidth= 0;
        while(!q.empty())
        {
            int n= q.size();
            ll firstIdx= q.front().second;
            ll lastIdx= q.back().second;
            maxWidth= max(maxWidth, lastIdx-firstIdx+1);

            // now do level wise traversal...
            while(n--)
            {
                TreeNode* curr= q.front().first;
                ll idx= q.front().second;
                q.pop();

                if(curr->left){
                    q.push({curr, 2*idx+1});
                }
                if(curr->right){
                    q.push({curr, 2*idx+2});
                }
            }
        } 
    return maxWidth;
    }
};

*/