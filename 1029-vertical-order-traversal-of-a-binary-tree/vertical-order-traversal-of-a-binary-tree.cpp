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

 // Approach -> using map<int,map<int,multiset<int>>>

 // map is used bcoz we need in sorted order
 // multiset can also store duplicates, also in sorted order

 // TC= O(N log N)
 // SC= O(N)


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        // base case
          if(!root) return {};

          queue<pair<TreeNode*,pair<int,int>>> q;
          q.push({root,{0,0}});

          // multiset can also store duplicates, also in sorted order 
          map<int,map<int,multiset<int>>> mp;
          mp[0][0].insert(root->val);

          while(!q.empty())
          {
             TreeNode* curr= q.front().first;
             int x= q.front().second.first;
             int y= q.front().second.second;
             q.pop();

             if(curr->left)
             {
                q.push({curr->left,{x-1,y+1}});
                mp[x-1][y+1].insert(curr->left->val);
             }

             if(curr->right)
             {
                q.push({curr->right,{x+1,y+1}});
                mp[x+1][y+1].insert(curr->right->val);
             }
          }

        vector<vector<int>> ans;
          for(auto it: mp)
          { 
              vector<int> temp;
              for(auto itr: it.second)
              {
                  for(auto j: itr.second)
                  {
                     temp.push_back(j);
                  }
              }
            ans.push_back(temp);  
          }
    return ans;
    }
};