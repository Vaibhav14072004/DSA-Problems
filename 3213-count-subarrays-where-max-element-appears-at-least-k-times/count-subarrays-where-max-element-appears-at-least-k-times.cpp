/* Return the number of subarrays where the maximum element of nums appears
   at least k times in that subarray.

// Similar Problems -> 
1. Length of longest substring with Atleast K Freq 
2. Length of Longest Subarray With AtMost K Frequency
*/

// TC= O(N)

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) 
    {
       int n= nums.size();
       long long ans= 0;
       int maxi= *max_element(nums.begin(),nums.end()); 

       int i= 0, j= 0;
       int cnt= 0;

       while(j < n)
       {
           if(nums[j]== maxi){
              cnt++;
           }

           // shrink the window if cnt > k
           while(cnt >= k)
           {
                ans+= (n-j);
                if(nums[i]== maxi){
                    cnt--;
                }
                i++;
           }
           j++;
       }
     return ans;  
    }
};