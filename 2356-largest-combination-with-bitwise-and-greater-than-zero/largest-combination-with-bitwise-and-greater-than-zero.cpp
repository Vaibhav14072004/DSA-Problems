/* 
Given constraint is 1 <= cand[i] <= 10^7

No of bits in 10^7 will be => (1 + upper bound[ Log 2 (10^7)])
 ->>> 24 

 If we do and (&) operation, only those numbers will give result > 0, 
 if they all have that particular bit = 1. 

 So instead of finding unique pairs, just find max no of set bits for all the bits from 0 to 31
 */

// TC= O(N)

class Solution {
public:
    int largestCombination(vector<int>& cand) {
         int n= cand.size();
         int maxLen= 0;
        
         // assuming 32 bit no, we can run loop till i=0 to i<32
         for(int i=0; i<24; i++)
         {
            int cnt= 0;
            for(int &num: cand)
            {
                // check if ith bit is set OR NOT
                if((num & (1<< i))!= 0)
                {
                    cnt++;
                }
            }

            maxLen= max(maxLen, cnt);
         }
        return maxLen; 
    }
};