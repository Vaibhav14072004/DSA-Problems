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


// Approach 1.2 -> Other way of storing parent using recursion..

// Creating adjacency list of each node instead of storing parent of each node
// and traverse level wise using adj list and queue

// TC= O(2*N)
// SC= O(N)

class Solution{
 public:
    void createAdj(TreeNode* root,TreeNode* parent,unordered_map<TreeNode*,vector<TreeNode*>> &adj, TreeNode* &startNode, int &start)
    {
        // base case
        if(root== NULL){
            return;
        }

        if(parent != NULL){
            adj[root].push_back(parent);
        }

        if(root->val== start){
            startNode= root;
        }
   
        if(root->left){
            adj[root].push_back(root->left);
        }

        if(root->right){
            adj[root].push_back(root->right);
        }

        createAdj(root->left,root,adj,startNode,start);
        createAdj(root->right,root,adj,startNode,start);
    }

    int amountOfTime(TreeNode* root, int start)
    { 
        // base case
        if(root== NULL) return 0; 

        unordered_map<TreeNode*,vector<TreeNode*>> adj;

        TreeNode* startNode= NULL;
        TreeNode* parent= NULL;
        createAdj(root,parent,adj,startNode,start);

        int time= 0;
        unordered_set<TreeNode*> visited;

        queue<pair<TreeNode*,int>> q;
        q.push({startNode,0});
        visited.insert(startNode);

        // now level wise traverse the nodes...
        while(!q.empty())
        {
            int n= q.size();
            time= max(time,q.front().second);

            while(n--)
            {
                TreeNode* node= q.front().first;
                int t= q.front().second;
                q.pop();
                
                for(auto it: adj[node])
                {
                    if(!visited.count(it))
                    {
                        q.push({it,t+1});
                        visited.insert(it);
                    }
                }
            }
        }
    return time;
    }
};









// Approach 1.1 -> Using BFS
// First store parent of each node in map, then traverse level wise and push nodes in queue with time+1

// TC= O(2*N)
// SC= O(2*N)

/*

class Solution {
public:
    int amountOfTime(TreeNode* root, int start)
    {
        // base case
        if(root== NULL){
            return 0;
        }

        unordered_map<TreeNode*,TreeNode*> mp;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* startNode= NULL;

        // first store parent of each node, so that we can traverse in both directions..
        while(!q.empty())
        {
            TreeNode* curr= q.front();
            q.pop();

            if(curr->val== start)
            {
                startNode= curr;
            }

            if(curr->left){
                mp[curr->left]= curr;
                q.push(curr->left);
            }

            if(curr-> right){
                mp[curr->right]= curr;
                q.push(curr->right);
            }
        }

        queue<pair<TreeNode*,int>> Queue;
        unordered_set<TreeNode*> visited;
        Queue.push({startNode,0});
        visited.insert(startNode);

        int time= 0;
        while(!Queue.empty())
        {
            int n= Queue.size();
            time= max(time,Queue.front().second);
            while(n--)
            {
                TreeNode* node= Queue.front().first;
                int t= Queue.front().second;
                Queue.pop();

                if(node->left && !visited.count(node->left))
                {
                    visited.insert(node->left);
                    Queue.push({node->left,t+1});
                }

                if(node->right && !visited.count(node->right))
                {
                    visited.insert(node->right);
                    Queue.push({node->right,t+1});
                }

                if(mp.count(node) && !visited.count(mp[node]))
                {
                    visited.insert(mp[node]);
                    Queue.push({mp[node],t+1});
                }
            }
        }
     return time;   
    }
};

*/