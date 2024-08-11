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



// TC= O(N*M)

/* Base case ->> when we have to only traverse the middle row atlast
    when all others paths are traversed...  
   Added 2 extra checks if(top <= bottom)  and other is if(left<= right)
*/


class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int> (n,-1));
        
        // Traverse matrix in spiral order...
        // m -> no of rows  &&  n -> no of columns

        int left= 0, right= n-1;
        int top= 0, bottom= m-1;

        while(left <= right && top <= bottom && head != NULL)
        {
               // move right...
               for(int i=left; i<= right && head != NULL; i++)
               {
                  ans[top][i]= head->val;
                  head= head->next;
               }

               top++;

               // move bottom...
               for(int i= top; i<= bottom && head != NULL; i++)
               {
                   ans[i][right]= head->val;
                   head= head->next;
               }

               right--;

               // move left...

            if(top <= bottom)
            {
               for(int i= right; i>= left && head != NULL; i--)
               {
                    ans[bottom][i]= head->val;
                    head= head->next;
                }
               bottom--;
            }
            
            if(left <= right)
            {
               for(int i=bottom; i>= top && head != NULL; i--)
               {
                   ans[i][left]= head->val;
                   head= head->next;
               }
               left++;
             }
         }
    return ans;
   }
};