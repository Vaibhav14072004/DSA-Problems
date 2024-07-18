// TC= O(N)

class Solution {
public:
   int ans= 0;

   vector<int> dfs(TreeNode* root, int dist, int &ans)
   {
       if(root== NULL) {};

       // if it is a leaf node... return 1.
       if(root->left== NULL && root->right== NULL)
       {
           return {1};
       }

       vector<int> leftVec;
       vector<int> rightVec;

       if(root->left)
       {
          leftVec= dfs(root->left,dist,ans);
       }

       if(root->right)
       {
           rightVec= dfs(root->right, dist,ans);
       }

       for(auto lv: leftVec)
       {
           for(auto rv: rightVec)
           {
               if(lv+rv <= dist)
               {
                   ans++;
               }
           }
       }

       vector<int> parent;
       for(auto lv: leftVec)
       {
            if(lv+1 <= dist)
            {
                parent.push_back(lv+1);
            }
       }

       for(auto rv: rightVec)
       {
          if(rv+1 <= dist)
          {
            parent.push_back(rv+1);
          }
       }
    return parent;
   }

      
    int countPairs(TreeNode* root, int dist) {
        if(root== NULL)  return 0;
        int ans= 0;
        dfs(root,dist,ans);
        return ans;
    }
};