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
    int i;
    TreeNode *helper(string str,int ph)
    {
        if(i>=str.length()) return NULL;
        int h=0;
        int pi=i;
        while(i<str.length() && str[i]=='-')
        {
            i++;
            h++;
        }
        if(h!=ph+1)
        {  
           i=pi; 
           return NULL;
        }
        int num=0;
        while(i<str.length() && str[i]!='-')
        {
            int p=str[i]-'0';
            num=(num*10)+p;
            i++;
        }
        TreeNode *root=new TreeNode(num);
        root->left=helper(str,h);
        root->right=helper(str,h);
        return root;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int i=0;
        return helper(traversal,-1);
    }
};