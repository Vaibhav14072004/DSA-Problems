// Approach 2 -> get path from (root to p) and (root to q)
// and then find traverse both paths and find common point...

// TC= O(N)   Sc= O(N)

class Solution{
public:
    bool getPath(TreeNode* root, TreeNode* target, vector<TreeNode*> &path)
    {
        if(root== NULL){
            return false;
        }
        
        path.push_back(root);

        if(root== target){
            return true;
        }

        if(getPath(root->left,target,path) || getPath(root->right,target,path))
        {
            return true;
        }

        path.pop_back(); // backtracking..
        return false;
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root== NULL){
            return NULL;
        }

        vector<TreeNode*> path1, path2;
         
        getPath(root, p, path1);
        getPath(root, q , path2);

        int j= 0;
        while(j < path1.size() && j < path2.size() && path1[j]== path2[j])
        {
            j++;
        }

       return path1[j-1];
    }
};






// Approach 1 -> Optimal 
// Tc= O(N)   Sc= O(1)

/*

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

*/