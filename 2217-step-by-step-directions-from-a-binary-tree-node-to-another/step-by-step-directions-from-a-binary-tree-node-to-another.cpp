// Approach 1 -> Using LCA
// First find path from (lcaToStart= LCA to startVal) , then (lcaToDest= LCA to destVal)....
// Add 'U' in ans corresponding to len of lcaToStart and then append lcaToDest directly..

// TC= O(4* N)
// SC= O(2* N)

class Solution {
public:

   // TC= O(N)
   TreeNode* getLCA(TreeNode* root, int startVal ,int destVal)
   {
       if(root== NULL){
           return NULL;
       }

       if(root->val== startVal || root->val== destVal)
       {
           return root;
       }

       TreeNode* leftN= getLCA(root->left,startVal,destVal);
       TreeNode* rightN= getLCA(root->right,startVal,destVal);

       if(leftN!= NULL && rightN != NULL)
       {
           return root;
       }

       if(leftN != NULL)
       {
         return leftN;
       }
       return rightN;
   }


// TC= O(N)
   bool getPath(TreeNode* LCA, int target, string &path)
   {
        if(LCA== NULL){
            return false;
        }

        if(LCA->val== target){
            return true;
        }

       // call for left subtree...
       path.push_back('L');
       if(getPath(LCA->left, target, path))
       {
           return true;
       }
       
       path.pop_back(); // backtracking...

       // now call for right subtree....
       path.push_back('R');
       if(getPath(LCA->right, target, path))
       {
        return true;
       }

       path.pop_back();

       return false;
   }

// TC= O(2* N)
    string getDirections(TreeNode* root, int startVal, int destVal) {
        // base case
        if(root== NULL){
            return "";
        }

        TreeNode* LCA= getLCA(root,startVal, destVal);

        string lcaToStart= "";
        string lcaToDest= "";

        getPath(LCA, startVal, lcaToStart);
        getPath(LCA, destVal, lcaToDest);

        // we should add 'U' in ans corresponding to length of lcaToStart
        // and then append lcaToDest string..

        string ans= "";
        for(int i=0; i<lcaToStart.size(); i++)
        {
            ans+= 'U';
        }
        ans+= lcaToDest;

    return ans;
    }
};