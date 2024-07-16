// Approach 1 -> Optimal 
// Tc= O(N)   Sc= O(1)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root== NULL){
            return NULL;
        }
        
        if(root== p || root== q){
            return root;
        }

        TreeNode* leftNode= lowestCommonAncestor(root->left, p, q);
        TreeNode* rightNode= lowestCommonAncestor(root->right, p, q);

        if(leftNode && rightNode){
            return root;
        }

        if(leftNode){
            return leftNode;
        }
        return rightNode;
    }
};