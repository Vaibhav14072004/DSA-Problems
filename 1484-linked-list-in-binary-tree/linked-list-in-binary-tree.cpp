/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

// TC= O(N*M)

class Solution {
public:
    bool solve(ListNode* head, TreeNode* root)
    {
        // if we have finished traversing linkedList, return true
        if(head== NULL){
            return true;
        }
        
        // if we have finished traversing tree, means given LinkedList NOT found
        if(root== NULL){
            return false;
        }

        if(head->val== root->val){
           return solve(head->next, root->left) || solve(head->next, root->right);
        }
       return false; 
    }


    bool isSubPath(ListNode* head, TreeNode* root)
    {
        // base case
        if(root== NULL){
            return false;
        }

        if(solve(head,root)){
            return true;
        }

        // check for left,right subpart of binary tree...
        return (isSubPath(head,root->left) || isSubPath(head,root->right));
    }
};