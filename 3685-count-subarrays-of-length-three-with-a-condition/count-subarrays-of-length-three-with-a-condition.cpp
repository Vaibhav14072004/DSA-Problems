class Solution {
public:
    int countSubarrays(vector<int>& nums)
    {
        int n= nums.size();
        if(n<3)
        {
            return 0;
        }

        if(n== 3)
        {
            if(2* (nums[0]+nums[2]) == (nums[1]))
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        int i= 1;
        int cnt= 0;
        while(i-1>= 0 && i+1 < n)
        {
            if(2*(nums[i-1]+ nums[i+1])== nums[i]) cnt++;
            
            i++;
        }

        return cnt;
    }
};