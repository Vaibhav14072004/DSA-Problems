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

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1; 

        priority_queue<long long> pq;  
        queue<TreeNode*> q;  
        q.push(root); 

        while (!q.empty()) {
            long long sum = 0;
            int levelSize = q.size(); 

           
            for (int i = 0; i < levelSize; i++) {
                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val;  

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }

            pq.push(sum); 
        }

        long long ans = 0;
        if(pq.size()<k) return -1;
        while (k-- && !pq.empty()) {
            ans = pq.top(); 
            pq.pop();  
        }

        return ans; 
    }
};