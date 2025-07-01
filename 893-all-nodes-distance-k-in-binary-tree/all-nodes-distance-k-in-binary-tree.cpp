/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// Approach 1.2 ->> Using BFS
// Creating adj list of each node instead of storing parent (using recursion)
// then traversing each node level wise using queue

// TC= O(3*N)
// SC= O(2*N), N for recursive stack space, N for queue

class Solution{
  public:
    void createAdj(TreeNode* root, TreeNode* parent, unordered_map<TreeNode*,vector<TreeNode*>> &adj)
    {
        // base case
        if(!root) return;

        if(parent != NULL){
            adj[root].push_back(parent);
        }

        if(root->left){
            adj[root].push_back(root->left);
        }

        if(root->right){
            adj[root].push_back(root->right);
        }

        createAdj(root->left,root,adj);
        createAdj(root->right,root,adj);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
       if(root== NULL){
          return {};
       }   
       
       // first create adj list using recursion..
       unordered_map<TreeNode*,vector<TreeNode*>> adj;
       TreeNode* parent= NULL;
       createAdj(root,parent,adj);

       queue<TreeNode*> q;
       unordered_set<TreeNode*> visited;

       q.push(target);
       visited.insert(target);

       // now traverse nodes level wise using queue..
       int level= 0;
       while(!q.empty())
       {
           int n= q.size();

           // all nodes at level k will be in queue
           if(level== k)
           {
              break;
           }

           while(n--)
           {
               TreeNode* curr= q.front();
               q.pop();
               for(auto it: adj[curr])
               {
                 if(!visited.count(it)){
                    q.push(it);
                    visited.insert(it);
                  }
                }
           }
        level++;   
       }
    
    // queue will be storing all nodes at level k
    vector<int> ans;

    while(!q.empty()){
       ans.push_back(q.front()->val);
       q.pop();
    }
   return ans;
  }
};







// Approach 1.1 -> Using BFS
// Storing parent of each node using queue
// then traversing each node level wise using queue

// TC= O(3*N)
// SC= O(2*N)

/*

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

*/