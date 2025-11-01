class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* curr = head;
        ListNode* prev = dummy;

        while (curr != NULL) {
            if (st.find(curr->val) != st.end()) {
                prev->next = curr->next;
                curr = curr->next;  // just move, don’t delete
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        ListNode* newHead = dummy->next;
        delete dummy; // safe to delete dummy
        return newHead;
    }
};
