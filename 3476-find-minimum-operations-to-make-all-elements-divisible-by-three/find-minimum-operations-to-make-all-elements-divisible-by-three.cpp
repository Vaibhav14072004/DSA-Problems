class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n= nums.size();
        
        int ans= 0;
        for(int i=0; i<n; i++)
        {
            int rem= (nums[i] % 3);
            ans+= min(rem, abs(rem-3));
        }
        return ans;
    }
};