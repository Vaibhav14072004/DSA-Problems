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

// Approach 2.2 ->> Using Max Heap
// TC= O(N log K)
// SC= O(N) 

class Solution{
public: 
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // base case
        if(root== NULL)
        {
            return -1;
        }

        priority_queue<long long> pq;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int n= q.size();
            long long levelSum= 0;
            while(n--)
            {
                TreeNode* node= q.front();
                q.pop();
                levelSum+= node->val;

                if(node->left)
                {
                    q.push(node->left);
                }

                if(node->right)
                {
                    q.push(node->right);
                }
            }

            // after completion of each level..
            pq.push(levelSum);
        }
        
        if(pq.size() < k)
        {
            return -1;
        }
        
        long long ans= -1;
        while(!pq.empty() && k--)
        {
           ans= pq.top();
           pq.pop();
        }
       return ans; 
    }
};







// Approach 2.1 -> Using Min heap(Priority_queue)

// Generally In case of finding largest ->> we use Min heap
// Generally In case of finding smallest ->> we use Max heap

// TC= O(N log K)
// SC= O(N) + O(K) -->> O(N)

/*

class Solution{
public: 
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // base case
        if(root== NULL)
        {
            return -1;
        }

        priority_queue<long long,vector<long long>,greater<long long>> pq;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n= q.size();
            long long levelSum= 0;

            for(int i=0; i<n; i++)
            {
                TreeNode* node= q.front();
                q.pop();
                levelSum+= node->val;

                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }

            // after completion of each level...
            pq.push(levelSum); 

            if(pq.size() > k)
            {
                pq.pop();
            } 
        }
        
        if(pq.size()== k)
        {
            return pq.top();
        }
       return -1; 
    }
};

*/









// Approach 1->>  Storing level order sums and then sorting it..
// TC O(N) + O(N log N) -->> O(N log N)
// SC= O(N) ->> worst case (skewed binary tree) but in balanced tree -> O(log n)

// TC= O(N log N)
// SC= O(N)

/*

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // base case
        if(root== NULL)
        {
            return -1;
        }

        vector<long long> levelOrder;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int n= q.size();
            long long levelSum= 0;

            for(int i=0; i<n; i++)
            {
                TreeNode* node= q.front();
                q.pop();
                levelSum+= node->val;

                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
            }
        levelOrder.push_back(levelSum);
        }
        
        // sort level order sum in descending order...
        sort(levelOrder.rbegin(), levelOrder.rend());
        
        if(k-1 >= 0 && levelOrder.size() >= k)
        return levelOrder[k-1];

        return -1;
    }
};

*/