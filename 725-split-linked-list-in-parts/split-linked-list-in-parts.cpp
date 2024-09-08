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

// TC= O(N+K)

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr= head;
        int len= 0;
        
        while(curr){
            curr= curr->next;
            len++;
        }

        int eachGrp= len/k;
        int rem= len % k;
                
        vector<ListNode*> ans(k, NULL);
        
        curr= head;
        ListNode* prev= NULL;

        for(int i=0; i< k; i++)
        {
             ans[i]= curr;

             for(int cnt= 1; cnt<= len/k + (rem > 0 ? 1 : 0); cnt++)
             {
                 prev= curr;
                 if(curr != NULL)
                 {
                  curr= curr->next;
                 }
             }
             
             if(prev != NULL){
                 prev->next= NULL;
             }

             rem--;
        }
    return ans;
    }
};







