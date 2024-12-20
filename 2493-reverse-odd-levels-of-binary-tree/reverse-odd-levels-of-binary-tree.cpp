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


// Approach 2 =>> DFS
// TC= O(N)
// SC= O[log 2 (N)]  ->> Recursive stack space

class Solution {
public:
   void solve(TreeNode* rootLeft,TreeNode* rootRight, int level)
   {    
        if(rootLeft== NULL || rootRight== NULL){
            return;
        }
 
        // if it is odd level.. do reversal...
        if(level % 2== 1)
        {
            int temp= rootLeft->val;
            rootLeft->val= rootRight->val;
            rootRight->val= temp;
        }
        
        // left is being replaced by right and vice versa
        solve(rootLeft->left, rootRight->right, level+1);
        solve(rootLeft->right, rootRight->left, level+1);
   }


    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root== NULL) 
          return NULL;
        
        // root-> left and root->right will be at 1st level...
        solve(root->left,root->right,1);
    return root;
    }
};








 // Approach 1 =>> BFS
 // TC= O(2*N) =>> O(N)
 // SC= O(N)

/*

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root== NULL) 
          return NULL;

        queue<TreeNode*> q;
        q.push(root);

        int level= 0;
        while(!q.empty())
        {   
            vector<TreeNode*> vec;
            int n= q.size();
            while(n--)
            {
                TreeNode* node= q.front();
                q.pop();
                vec.push_back(node);

                if(node->left){
                    q.push(node->left);
                }

                if(node->right){
                    q.push(node->right);
                }
            }

            // if curr level is ODD, then do reverse operation..
            if(level % 2== 1)
            {
                int i=0, j= vec.size()-1;
                while(i < j)
                {
                    int temp= vec[i]->val;
                    vec[i]->val= vec[j]->val;
                    vec[j]->val= temp;
                    i++;
                    j--;
                }
            }

            level++;
        }
        return root;
    }
};

*/