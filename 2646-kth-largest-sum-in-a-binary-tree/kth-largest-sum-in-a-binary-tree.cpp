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

// Approach 1->>  Storing level order sums and then sorting it..
// TC O(N) + O(N log N) -->> O(N log N)
// SC= O(N) ->> worst case (skewed binary tree) but in balanced tree -> O(log n)

// TC= O(N log N)
// SC= O(N)

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