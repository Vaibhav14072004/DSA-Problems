/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Approach 1 -> Using BFS
// TC= O(N)
// SC= O(N)

class Solution {
public:
    void findParents(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent)
    {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* node= q.front();
            q.pop();

            if(node->left){
                parent[node->left]= node;
                q.push(node->left);
            }

            if(node->right){
                parent[node->right]= node;
                q.push(node->right);
            }
        }
    }


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
       if(root== NULL){
          return {};
       }   
       
       // {node, parent}
       unordered_map<TreeNode*,TreeNode*> parent;
       findParents(root,parent);

       queue<TreeNode*> q;
       q.push(target);
       
       int level= 0;
       unordered_set<TreeNode*> visited;

       while(!q.empty())
       {
           int n= q.size();

           if(level== k){
              break;
           } 
           
           while(n--)
           {
               TreeNode* node= q.front();
               q.pop();
               visited.insert(node);

               if(node->left && !visited.count(node->left)){
                  q.push(node->left);
                  visited.insert(node->left);
               } 

               if(node->right && !visited.count(node->right)){
                   q.push(node->right);
                   visited.insert(node->right);
               }

               if(parent.find(node) != parent.end() && !visited.count(parent[node]))
               {
                  q.push(parent[node]);
                  visited.insert(parent[node]);
               }
           }
           level++;
       }

       vector<int> ans;
       while(!q.empty())
       {
           int val= q.front()->val;
           q.pop();
           ans.push_back(val);
       }
    return ans;
    }
};