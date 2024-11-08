// Approach 1 -> Brute Force Approach
// TC= O(N)

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n= nums.size();
        
        int XOR= 0;
        for(int i=0; i<n; i++)
        {
           XOR^= nums[i];
        }
         
        // Max k can be any value between 0 to [pow(2, maximumBit)] - 1
        // mask will have all set bits ie 111 ....
        int mask= (1<< maximumBit) - 1;
        
        vector<int> ans(n);
        for(int i=0; i<n; i++)
        { 
            // when we take XOR ^ (fliped XOR) we get max value, that is all set bits 111..
            // so this flipped XOR will be our maxK value
            ans[i]= XOR^ mask;

            // after every iteration, last element is removed, a^a= 0
            XOR^= nums[n-i-1]; 
        }
      return ans;
    }
};