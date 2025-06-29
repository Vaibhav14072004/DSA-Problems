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

// Approach 1 -> Using BFS
// TC= O(2*N)

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