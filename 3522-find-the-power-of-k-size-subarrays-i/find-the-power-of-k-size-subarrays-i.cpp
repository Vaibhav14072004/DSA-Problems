// Approach 1 -> Brute Force Approach
// TC= O(N*K)

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int> ans(n-k+1, -1);
        int idx= 0;
         
        for(int i=0; i<=n-k; i++)
        {
            bool flag= false;
            for(int j= i+1; j<i+k; j++)
            {
                if(nums[j]-nums[j-1] != 1)
                {
                    ans[idx++]= -1;
                    flag= true;
                    break;
                }
            }

            if(!flag)
            {
               ans[idx++]= nums[i+k-1];
            }
        }
    return ans;
    }
};




