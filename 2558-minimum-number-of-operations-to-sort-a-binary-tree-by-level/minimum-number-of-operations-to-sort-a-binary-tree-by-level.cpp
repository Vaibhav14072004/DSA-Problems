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

// TC= O[L* (N log N + N+ N)] =>> O(L*N*log N)

class Solution {
public:
    int minOperations(vector<int> &vec)
    {
        int n= vec.size();
        vector<int> sortedVec= vec;
        sort(sortedVec.begin(),sortedVec.end());
        
        // map to keep track of indexes..
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++)
        {
            mp[vec[i]]= i;
        }

        // now traverse sorted vec,...
        int cnt= 0;
        for(int i=0; i<n; i++)
        {
            // if array is NOT sorted, correct the indexes in mp..
            if(vec[i] != sortedVec[i])
            {
                int index= mp[sortedVec[i]];
                mp[vec[i]]= index;
                mp[sortedVec[i]]= i;

                swap(vec[i], vec[index]);
                cnt++;
            }
        }
    return cnt;
    }


    int minimumOperations(TreeNode* root) {
        if(root== NULL)
          return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int cnt= 0;
        while(!q.empty())
        {
            // to keep track of indexes of each node at a level
            vector<int> vec;
            int n= q.size();

            while(n--)
            {
               TreeNode* node= q.front();
               q.pop();
               vec.push_back(node->val);

               if(node->left)
               {
                  q.push(node->left);
               }

               if(node->right)
               {
                  q.push(node->right);
               }
            }

            // now find min operations to sort vec, after completion of each level...
            cnt+= minOperations(vec);
        }
       return cnt; 
    }
};