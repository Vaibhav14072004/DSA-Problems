class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums)
    {
        int n= nums.size();
        long long ans= 0;
        int curr= 0;
        for(int i=0; i<n; i++)
        {
            if(nums[i]== 0){
               curr++;
            }
            else{
               ans+= 1LL*(curr)*(curr+1)/2;
                curr= 0;
            }
        }
        
        // add last zeroes also;
        ans+= 1LL*(curr)*(curr+1)/2;
        return ans;
    }
};