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
// TC= O(N)

class Solution{
  public:
    vector<int> rightSideView(TreeNode* root)
    {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);

        vector<int> ans;
        while(!q.empty())
        {
            int n= q.size();
            for(int i=0; i<n; i++)
            {
                TreeNode* curr= q.front();
                q.pop();

                if(i== n-1)
                {
                    ans.push_back(curr->val);
                }
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
        }
     return ans;   
    }
};






// Approach 1 -> Using DFS
// TC= O(N)

// SC= O(Height of tree) bcoz of recursion stack space
// SC= O(log n) in balanced tree, O(n) for skewed tree

/*

class Solution {
public:
    void DFS(TreeNode* root,int level,vector<int> &vec)
    {
        if(!root) return;

        if(vec.size() <= level){
            vec.push_back(root->val);
        }
        
        // first call for root->right, then after root->left
        if(root->right){
            DFS(root->right,level+1,vec);
        }
        if(root->left){
            DFS(root->left,level+1,vec);
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> vec;
        DFS(root,0,vec);
        return vec;
    }
};

*/