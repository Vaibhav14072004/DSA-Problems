// Bitwise AND would be max for largest value in the array... find its continuous streak to return ans..

// TC= O(N)

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n= nums.size();
        
        int maxi= *max_element(nums.begin(), nums.end());

        int streak= 0, maxStreak= 0;

        for(int i=0; i<n; i++)
        {
           if(nums[i]== maxi)
           {
              streak++;
              maxStreak= max(maxStreak, streak);
           }
           else
           {
              streak= 0;
           }
        }
      return maxStreak;  
    }
};