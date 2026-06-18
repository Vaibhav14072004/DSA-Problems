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


// Approach 3 -> Most Optimized -> One paas solution 
// Using DFS

// TC= O(N)
// SC= O(N) -> recursive stack space


class Solution{
  public:
    int DFS(TreeNode* root,int start,int &ans)
    {
        if(root== NULL) return 0;

        int leftHt= DFS(root->left,start,ans);
        int rightHt= DFS(root->right,start,ans);

        if(root->val== start)
        {
            ans= max(leftHt,rightHt);
            return -1;
        }

        // if both heights are positive, means root not found int his path
        else if(leftHt >= 0 && rightHt >= 0)
        {
            return max(leftHt,rightHt)+1;
        }

         // if one of them is negative ,means root is there in its path
        else
        {
           ans= max(ans, abs(leftHt)+ abs(rightHt));
           return min(leftHt,rightHt)-1;
        }
    }

    int amountOfTime(TreeNode* root, int start) 
    {
        if(root== NULL) return 0;

        int ans= 0;
        DFS(root,start,ans);
        return ans;
    }
};







// Approach 1.2 -> Using BFS + (DFS for storing parent of each node)

// Other way of storing parent using recursion..
// Creating adjacency list of each node instead of storing parent of each node
// and traverse level wise using adj list and queue

// TC= O(2*N)
// SC= O(2*N) -> N for recurison stack space, N for queue

/*

class Solution{
  public:  
    void findParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent, int &start, TreeNode* &startNode)
    {
        if(root== NULL) return;

        if(root->val== start) startNode= root;

        if(root->left)
        {
            parent[root->left]= root;
        }

        if(root->right)
        {
            parent[root->right]= root;
        }

        findParent(root->left,parent,start,startNode);
        findParent(root->right,parent,start,startNode);
    }


    int amountOfTime(TreeNode* root, int start) 
    {
        if(root== NULL) return 0;
        unordered_map<TreeNode*,TreeNode*> parent;

        TreeNode* startNode= NULL;
        findParent(root,parent,start,startNode);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        q.push(startNode);
        visited.insert(startNode);

        int level= 0;
        while(!q.empty())
        {
            int n= q.size();
            level++;

            while(n--)
            {
                TreeNode* node= q.front();
                q.pop();

                if(node->left && !visited.count(node->left))
                {
                    visited.insert(node->left);
                    q.push(node->left);
                }

                if(node->right && !visited.count(node->right))
                {
                    visited.insert(node->right);
                    q.push(node->right);
                }

                if(parent.count(node) && !visited.count(parent[node]))
                {
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
        }
        return level-1;
    }
};

*/





// Approach 1.1 -> Using BFS

// Storing parent of each node using queue
// First store parent of each node in map, then traverse level wise and push nodes in queue with time+1

// TC= O(2*N)
// SC= O(2*N)

/*

class Solution {
public:
   TreeNode* findParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parent, int start)
   {
        if(root== NULL) return NULL;

        queue<TreeNode*> q;
        q.push(root);

        TreeNode* startNode;
        while(!q.empty())
        {
            TreeNode* node= q.front();
            q.pop();

            if(node->val== start)
            {
                startNode= node;
            }

            if(node->left)
            {
                parent[node->left]= node;
                q.push(node->left);
            }

            if(node->right)
            {
                parent[node->right]= node;
                q.push(node->right);
            }
        }
        return startNode;
   }

    int amountOfTime(TreeNode* root, int start) 
    {
        if(root== NULL) return 0;
        int ans= 0;
        
        unordered_map<TreeNode*,TreeNode*> parent;
        TreeNode* startNode= findParent(root,parent,start);

        queue<TreeNode*> q;
        q.push(startNode);

        unordered_set<TreeNode*> visited;
        visited.insert(startNode);
        
        int level= 0;
        while(!q.empty())
        {
           int n= q.size();
           while(n--)
           {
              TreeNode* node= q.front();
              q.pop();
              
              if(node->left && !visited.count(node->left))
              {
                 visited.insert(node->left);
                 q.push(node->left);
              }

              if(node->right && !visited.count(node->right))
              {
                visited.insert(node->right);
                q.push(node->right);
              }

              if(parent.count(node) && !visited.count(parent[node]))
              {
                visited.insert(parent[node]);
                q.push(parent[node]);
              }
           }
           level++;
        }

    // bcoz at the end, one extra level have been incremented
    return level-1;
    }
};

*/