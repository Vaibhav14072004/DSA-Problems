class Solution {
public:
    int smallestIndex(vector<int>& nums) 
    {
        int n= nums.size();
        for(int i=0;i<n;i++)
        {
            string s= to_string(nums[i]);
            int sum=0;
            for(auto j:s)
            {
                sum+= j-'0';
            }
            if(sum==i)
            {
                return i;
            }
        }    
        return -1;
    }
};