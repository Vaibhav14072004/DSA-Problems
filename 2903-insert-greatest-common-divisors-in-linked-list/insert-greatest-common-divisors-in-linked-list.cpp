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

// TC= O[N* log(min(a,b)]

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head)
    {
        // base case..
        if(head== NULL || head->next== NULL)
        {
            return head;
        }

        ListNode* prev= head;
        ListNode*curr= head->next;

        while(curr != NULL)
        {
            // TC for gcd() is log(min(a,b))...
            int gcd= __gcd(curr->val, prev->val);

            ListNode* temp= new ListNode(gcd); 
            prev->next= temp;
            temp->next= curr;

            prev= curr;
            curr= curr->next;
        }
      return head;  
    }
};