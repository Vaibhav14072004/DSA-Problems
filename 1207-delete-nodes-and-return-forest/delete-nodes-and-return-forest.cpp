// TC= O(N)

class Solution {
public:
    TreeNode* dfs(TreeNode* root, unordered_set<int> &st, vector<TreeNode*> &ans)
    {
         if(root== NULL){
             return NULL;
         }
         
         // first call for left and right until it exists/..
         root->left= dfs(root->left, st, ans);
         root->right= dfs(root->right, st, ans);
        
        // if we have to delete this node... store its left and right child, if exists.. 
         if(st.find(root->val) != st.end())
         {
              if(root->left)
              {
                  ans.push_back(root->left);
              }

              if(root->right)
              {
                 ans.push_back(root->right);
              }
            
            return NULL; // bcoz we have to delete this node..
         }
        
        // if we have to NOT delete this node.. return root
         else
         {
            return root;
         }
    }


    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(root== NULL){
            return {};
        }

        vector<TreeNode*> ans;
        unordered_set<int> st(to_delete.begin(), to_delete.end());

        dfs(root, st, ans);
        
        // if we have to not delete root of tree, push it also in ans...
        if(st.find(root->val) == st.end())
        {
             ans.push_back(root);
        }

        return ans;
    }
};