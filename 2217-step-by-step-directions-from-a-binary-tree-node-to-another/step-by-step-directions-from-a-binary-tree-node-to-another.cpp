// Approach 2 -> Without finding LCA
// Get path from root node to start node and to dest node
//  Traverse both paths till a common node NOT found -> which is LCA
// Add 'U' in ans till len of rem path of start Node and append directly path of dest node

// TC= O(3*N)
// SC= O(2*N)

class Solution{
public: 

// Its return type is made bool so that its execution can be stopped ...
// but if we made return type void then we need to pass additional argument found to stop execution

    bool getPath(TreeNode* root, int target, string &path){
           if(root== NULL)
           {
               return false;
           }

           if(root->val== target)
           {
               return true;
           }

           // call for left subtree...
           path.push_back('L');
           if(getPath(root->left, target, path))
           {
              return true;
           }

           path.pop_back();  // backtracking...

           // call for right subtree....
           path.push_back('R');
           if(getPath(root->right, target, path))
           {
              return true;
           }
           
          path.pop_back();  // backtracking..
          return false;
    }


    string getDirections(TreeNode* root, int startVal, int destVal)
    {
        // base case
        if(root== NULL){
            return "";
        }

        string rootToStart= "";
        string rootToDest= "";

        getPath(root, startVal, rootToStart);
        getPath(root, destVal, rootToDest);

        string ans= "";
        
        // skip the path until we find common node(LCA)
        int j= 0;
        while(j < rootToStart.size() && j < rootToDest.size() && rootToStart[j] == rootToDest[j])
        {
            j++;
        }
        
        // Add 'U' to ans equals to size of remaining path of (root to start)
        int rem1= rootToStart.size()-j;
        while(rem1--){
            ans+= 'U';
        }
        
        // Append the rem path of (root to end) as it is in ans string..
        ans+= rootToDest.substr(j);
        return ans;
    }
};










// Approach 1 -> Using LCA -> 3eats 55.35 % 

// First find path from (lcaToStart= LCA to startVal) , then (lcaToDest= LCA to destVal)....
// Add 'U' in ans corresponding to len of lcaToStart and then append lcaToDest directly..

// TC= O(4* N)
// SC= O(2* N)

/*

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

*/