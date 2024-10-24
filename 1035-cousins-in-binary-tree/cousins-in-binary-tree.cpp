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

// Approach -> Using level order traversal...
// TC= O(N)
// SC= O(Depth of tree) ->> O(log n)

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y){
        // base case
        if(root== NULL)
        {
            return false;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int n= q.size();
            int parentX= -1, parentY= -1;

            while(n--)
            {
                TreeNode* node= q.front();
                q.pop();
                
                if(node->left)
                {
                    if(node->left->val== x)
                    {
                        parentX= node->val;
                    }
                    else if(node->left->val== y)
                    {
                        parentY= node->val;
                    }
                    q.push(node->left);
                }

                if(node->right)
                {
                    if(node->right->val== x)
                    {
                        parentX= node->val;
                    }
                    else if(node->right->val== y)
                    {
                        parentY= node->val;
                    }
                    q.push(node->right);
                }
            }

                if(parentX != -1 && parentY != -1)
                {
                    return parentX != parentY;
                }
                
                // If one of them is found and the other is not, they are not cousins
                else if(parentX != -1 || parentY != -1)
                {
                    return false;
                }
            }
    return false;
    }
};