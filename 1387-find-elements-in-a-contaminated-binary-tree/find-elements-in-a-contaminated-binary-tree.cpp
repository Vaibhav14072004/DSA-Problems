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

// Approach 2 ->> BFS
// TC= O(N)

class FindElements {
public:
    unordered_set<int> st;

    void BFS(TreeNode* root,int x)
    {
        if(root== NULL){
            return;
        }

        queue<TreeNode*> q;
        root->val= x;
        q.push(root);
        st.insert(x);

        while(!q.empty())
        {
            TreeNode* node= q.front();
            int value= node->val;
            q.pop();
            
            if(node->left)
            {
                node->left->val= (2*value)+1;
                q.push(node->left);
                st.insert(node->left->val);
            }

            if(node->right)
            {
                node->right->val= (2*value)+ 2;
                q.push(node->right);
                st.insert(node->right->val);
            }
        }
    }

    FindElements(TreeNode* root) {
       st.clear();
       BFS(root,0);
    }
    
    bool find(int target) {
       return st.count(target); 
    }
};








 // Approach 1 -> DFS
 // TC= O(N)

/*

class FindElements {
public:
    unordered_set<int> st;

    void DFS(TreeNode* root,int x)
    {
        if(root== NULL){
            return;
        }
        root->val= x;
        st.insert(x);
        DFS(root->left,2*x+1);
        DFS(root->right,2*x+2);
    }

    FindElements(TreeNode* root) {
       st.clear();
       DFS(root,0);
    }
    
    bool find(int target) {
       return st.count(target); 
    }
};

*/


/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */