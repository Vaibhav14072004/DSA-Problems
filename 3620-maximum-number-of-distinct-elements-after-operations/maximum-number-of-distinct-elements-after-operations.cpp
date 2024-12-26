// TC= O(N)

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n= nums.size();
        
        // sort in ascending order..
        sort(nums.begin(),nums.end());
        
        // start with smallest possible no
        int prev= nums[0]-k;
        int cnt= 1;

        for(int i=1; i<n; i++)
        {
            // to make prev= prev+1, if possible..
            if(prev+1 >= nums[i]-k && prev+1 <= nums[i]+k)
            {
                prev= prev+1;
                cnt++;
            }
            else if(prev < nums[i]-k)
            {
                prev= nums[i]-k;
                cnt++;
            }
        }
    return cnt;
    }
};