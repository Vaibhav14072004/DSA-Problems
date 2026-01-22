class Solution {
public:
    bool checkSorted(vector<int> &nums)
    {
        int n= nums.size();
        if(n== 1) return true;
        for(int i=1; i<n; i++)
        {
            if(nums[i-1] > nums[i]) return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int n= nums.size();

        int cnt= 0;
        while(!checkSorted(nums))
        {
            cnt++;
            int minSum= INT_MAX;
            int idx= -1;
            for(int i=1; i<nums.size(); i++)
            {
                if(nums[i-1]+ nums[i] < minSum)
                {
                    minSum= nums[i-1]+nums[i];
                    idx= i;
                }
            }

            vector<int> temp;
            for(int j=0; j<nums.size(); j++)
            {
                if(j== idx-1)
                {
                    temp.push_back(minSum);
                    j++;
                }
                else
                {
                    temp.push_back(nums[j]);
                }
            }

            nums= temp;
        }
    return cnt;    
    }
};