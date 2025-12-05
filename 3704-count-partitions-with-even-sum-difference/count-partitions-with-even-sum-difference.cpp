class Solution {
public:
    int countPartitions(vector<int>& nums) {
      int n= nums.size();
      int sum= 0;

      for(int i=0;i<n; i++)
      {
        sum+= nums[i];
      } 

     int currSum= 0, ans= 0;
      for(int i=0; i<n-1; i++)
      {
        currSum+= nums[i];
        int rem= sum- currSum;

        if((currSum-rem) % 2 == 0) ans++;
      }  
     return ans; 
    }
};