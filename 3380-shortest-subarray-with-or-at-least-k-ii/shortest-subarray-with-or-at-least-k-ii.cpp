// Ques of Sliding Window + Bit Manipulation

// TC= O(32* N)

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
         int n= nums.size();
         
         // To store the cnt of set bits.. useful when we have to reduce the window
         vector<int> bits(32,0);

         int i=0, j= 0, currOR= 0;
         int minLen= n+1;

         while(j< n)
         {
             currOR|= nums[j];

             for(int idx=0; idx<32; idx++)
             {
                // if the i th bit is set..
                 if(nums[j] & (1<<idx))
                 {
                     bits[idx]++;
                 }
             }

            // shrink the curr window, reduce cnt for set bits of nums[i]
            while(i<= j && currOR >= k)
            {
                minLen= min(minLen, j-i+1);

                for(int idx= 0; idx<32; idx++)
                {
                    // to check if the i th bit is set 
                     if(nums[i] & (1<< idx))
                     {
                         bits[idx]--;  
                         if(bits[idx]== 0)
                         {
                            currOR-= (1<<idx);
                         }
                     }
                }
             i++;
            }
           
           j++;
         }

        if(minLen > n) return -1;

        return minLen; 
    }
};