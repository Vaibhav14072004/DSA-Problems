class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
         int curr=1,prev=0;
         int longest=0;

         int ans=0;
        
        for(int i=1;i<nums.size();i++){
               
               if(nums[i]>nums[i-1]){
                   curr++;
               }

               else{
                  prev=curr;
                  curr=1;
               }
              
              longest=max(longest,curr);
                 
              ans=max(ans,max(longest/2,min(curr,prev)));


        }


        return ans;

    }
};