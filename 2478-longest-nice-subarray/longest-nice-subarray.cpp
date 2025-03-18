// Approach 2 -> Sliding Window
// TC= O(2*N)

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n= nums.size();
        int maxLen= 1;// min 1 length can be possible
        int i=0, j= 0, mask= 0;

        while(j < n)
        {
            while((mask & nums[j]) != 0)
            {
                // we have to remove the set bits of nums[i] from mask, so take XOR
                mask= mask ^ nums[i];
                i++;
            }
            
            maxLen= max(maxLen, j-i+1);
            mask= mask | nums[j];
            j++;
        }
    return maxLen;
    }
};





//  ----- TLE ----------
// Approach 1 ->> Using 2 for loops
// TC= O(N^2)

/*

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n= nums.size();
        int maxLen= 0;

        for(int i=0; i<n; i++)
        {
            int mask= 0;
            for(int j=i; j<n; j++)
            {
               if((mask & nums[j]) != 0){
                  break;
               }

               // we have done OR bcoz this will help us knowing which bits are 1
                mask= mask | nums[j];
                maxLen= max(maxLen, j-i+1);
            }
        }
      return maxLen;  
    }
};

*/