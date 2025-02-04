class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size(), sum=0, ans=INT_MIN;       
        for(int i=0;i<n;i++){
            if(i>0&&nums[i]>nums[i-1]) sum+=nums[i];
            else sum=nums[i];
            ans=max(ans,sum);
        }
        return ans;
    }
};