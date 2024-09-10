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



// Approach 1 -> Using stl function for gcd calculation...
// TC= O[N* log(min(a,b)]

class Solution {
public:
    int gcd1(int a, int b)
    {
        if(b== 0)
        {
            return a;
        }
       return gcd1(b, a % b); 
    }

    int gcd2(int a, int b)
    {
        while(b != 0)
        {
            int temp= b;
            b= a % b;
            a= temp;
        }
       return a; 
    }


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

            // int gcd= __gcd(curr->val, prev->val);

           // int gcd= gcd1(curr->val, prev->val);
            int gcd= gcd2(curr->val, prev->val);

            ListNode* temp= new ListNode(gcd); 
            prev->next= temp;
            temp->next= curr;

            prev= curr;
            curr= curr->next;
        }
      return head;  
    }
};