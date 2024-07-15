// TC= O(N)

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
         unordered_map<int,TreeNode*> mp;
         unordered_set<int> childSet;

        // -----  TC= O(N) -----
         for(vector<int> &it : descriptions)
         {
            int parent= it[0];
            int child= it[1];
            int isLeft= it[2];

            if(mp.find(parent) == mp.end())
            {
                mp[parent]= new TreeNode(parent);
            }

            if(mp.find(child) == mp.end())
            {
                mp[child]= new TreeNode(child);
            }

            if(isLeft== 1)
            {
                mp[parent]->left= mp[child];
            }

            else
            {
                mp[parent]->right= mp[child];
            }

        // if this particular node is NOT a child node of anyone, then this would be ROOT node
            childSet.insert(child);
         }
        

        //------ TC= O(N)  ------
        // To find rooot node...
         for(vector<int> &itr: descriptions)
         {
            int parent= itr[0];

            // if this particular node is NOT find in childSet.. means it is ROOT node
            if(childSet.find(parent) == childSet.end())
            {
                return mp[parent];
            }
         }

         return NULL;
    }
};