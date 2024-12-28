/*
 NOTE =>> If we have to return no of edges as Diameter =>>>
      currDiameter= leftHt+ rightHt

      But if we have to return no of nodes as Diameter =>>.
      currDiameter= leftHt + rightHt+ 1

*/

// Approach 3 

class Solution{
public:
  int calcHt(TreeNode* root, int &ans) {
        if (root== NULL) return 0;

        int leftHt = calcHt(root->left, ans);
        int rightHt = calcHt(root->right, ans);

        ans = max(ans, leftHt + rightHt);
        return 1 + max(leftHt, rightHt);
    }

    int diameterOfBinaryTree(TreeNode* root)
    {
       if(root== NULL){
           return 0;
       }
    
    int ans= 0;
    calcHt(root,ans);
    return ans;
    }
};



// Approach 2 => Using pointer 
// TC= O(n)

/*

class Solution{
public:
     int calcDiameter(TreeNode* root, int *height)
     {
         if(root== NULL){
             *height= 0;
             return 0;
         }
 
         int lh=0, rh= 0;
         int leftDia= calcDiameter(root->left, &lh);
         int rightDia= calcDiameter(root->right, &rh);

         int currDia= lh+ rh;
         // If we have to count Nodes instead of edges =>> currDia= lh+ rh + 1

         *height= max(lh, rh)+ 1;

         return max(currDia, max(leftDia, rightDia));
     }


    int diameterOfBinaryTree(TreeNode* root) {
        int height= 0;
    return calcDiameter(root,&height);
    }
};

*/




// Approach 1 => Recursion 
// TC= O(n^2)

/*

class Solution {
public:
// TC= O(n) for calcHt
    int calculateHeight(TreeNode* root)
    {
       if(root== NULL){
           return 0;
       }

       int leftHt= calculateHeight(root->left);
       int rightHt= calculateHeight(root->right);
       return 1 + max(leftHt, rightHt);
    }

// TC= O(n^2) for calcDia
    int diameterOfBinaryTree(TreeNode* root) {
        // base case
        if(root== NULL){
            return 0;
        }

        // Two Cases :: ->>>
        // 1. Root Node included in diameter =>> (leftHt+ rightHt+ 1)
        // 2. Root Node NOT included in diameter => max(leftDiameter, rightDiameter)
    
       int leftHt= calculateHeight(root->left);
       int rightHt=  calculateHeight(root->right);

       // If ques m -> node count krne ho =>> add +1
       // if ques m -> edge count krne ho => NOT add +1
      int currDia= leftHt+ rightHt;

      int leftDia= diameterOfBinaryTree(root->left);
      int rightDia= diameterOfBinaryTree(root->right);

      return max(currDia, max(leftDia, rightDia));
    }
};

*/