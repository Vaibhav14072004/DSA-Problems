class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n= nums.size();

        // base case
        if(n<3) return 0;

        int cnt= 0, ans= 0;
        for(int i=2; i<n; i++)
        {
            if(nums[i-1]-nums[i-2] == nums[i]-nums[i-1])
            {
                cnt++;     
               ans+= cnt;  
            }
            else
            {
                cnt= 0;
            }
        }
       return ans; 
    }
};