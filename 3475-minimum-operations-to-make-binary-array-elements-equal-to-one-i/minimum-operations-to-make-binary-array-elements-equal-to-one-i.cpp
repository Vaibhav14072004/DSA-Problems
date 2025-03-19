// Approach 1 
// TC= O(N)

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n= nums.size();
        int ans= 0;

        for(int i=0; i<n; i++)
        {
           if(nums[i]== 1){
              continue;
           } 

           // if nums[i]== 0
           if(i+2 < n)
           {
               ans++;
               nums[i] ^= 1;
               nums[i+1] ^= 1;
               nums[i+2] ^= 1;  
               // or we can also do, nums[i+1] = !nums[i+1] 
           }
           
           // if only last 2 elements of arra are left, but they are also zero
           else
           {
              return -1;
           }
        }
      return ans;  
    }
};