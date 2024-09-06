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

// TC= O(N + N) -> O(N)

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        ListNode* dummy= new ListNode(-1);
        dummy->next= head;

        ListNode* curr= head;
        ListNode* prev= dummy;

        unordered_set<int> st(nums.begin(), nums.end());

        while(curr != NULL)
        {
            // delete curr node if it is present in the set
            if(st.find(curr->val) != st.end())
            {
                prev->next= curr->next;
                ListNode* temp= curr;
                curr= curr->next;
                delete temp;
            }

            else
            {
                prev= curr;
                curr= curr->next;
            }
        }

       ListNode* newHead= dummy->next;
       delete dummy;
       return newHead;
    }
};