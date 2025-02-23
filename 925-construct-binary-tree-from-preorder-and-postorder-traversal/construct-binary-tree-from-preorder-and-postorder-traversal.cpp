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
class Solution {
public:
    TreeNode* solve(int preSt, int postSt, int preEnd, vector<int>&preorder, vector<int>&postorder, unordered_map<int,int>&mp){
        if(preSt > preEnd) 
            return NULL;
        TreeNode* root = new TreeNode(preorder[preSt]);
        if(preSt == preEnd){
            return root;
        }
        int nextNode = preorder[preSt+1];
        int j = mp[nextNode];
        int num = j-postSt+1;

        root->left = solve(preSt+1,postSt,preSt+num,preorder,postorder,mp);
        root->right = solve(preSt+num+1,j+1,preEnd,preorder,postorder,mp);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++){
            mp[postorder[i]] = i;
        }
        return solve(0,0,n-1,preorder,postorder,mp);
    }
};