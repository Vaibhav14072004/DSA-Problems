class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n= nums.size();
        int sum= 0;
        for(int i=0; i<n; i++) sum+= nums[i];

        int curr= 0,cnt=0;
        for(int i=0; i<n; i++)
        {
            curr+= nums[i];
            if(nums[i]== 0)
            {
                int rem= sum-curr;
                if(curr== rem)
                {
                    cnt+= 2;
                }
                else if(abs(curr-rem)== 1)
                {
                    cnt++;
                }
            }
        }
      return cnt;
    }
};