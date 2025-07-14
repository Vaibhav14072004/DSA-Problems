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
class Solution {
    int findLength(ListNode* head){
        ListNode* curr = head;
        int length =  0;
        while(curr != nullptr){
            length++;
            curr = curr -> next;
        }
        return length;
    }
public:
    int getDecimalValue(ListNode* head) {

        int length = findLength(head);

        int convertedValue = 0;
        ListNode* curr = head;

        while(curr != nullptr){
            length--;
            if(curr -> val == 1){
                convertedValue += 1 << length;
            }
            curr = curr -> next;
        }
        
        return convertedValue;
    }
};