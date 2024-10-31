/*   ----- INTUITION -----
    Make a LIS array that will give no of increasing subsequence till
    that index starting from zero index.. (starting from 0th index)

    Also make a LDS array that will give no of decreasing sbsequence
    till that index to end .. (starting from end of array)...
    

    [Longest Increasing Subsequence] <<<- Centre Index ->>> [Longest Decreasing subsequence]
*/


// Approach 2 -> Finding LIS,LDS using Binary Search
// TC= O(N Log N)

class Solution{
public:
    void solve(vector<int> &nums, vector<int> &dp,int n)
    {
        vector<int> vec;
        vec.push_back(nums[0]);
        for(int i=1; i<n; i++)
        {
            if(nums[i] > vec.back())
            {
                vec.push_back(nums[i]);
                dp[i]= vec.size();   // to store length of LIS upto index i
            }
            else
            {
                // lower bound func to find index of just greater equal element than nums[i] in vec..
                int index= lower_bound(vec.begin(),vec.end(),nums[i])- vec.begin();
                vec[index]= nums[i];
                dp[i]= index+1;
            }
        }
        // return vec.size();
    }


    int minimumMountainRemovals(vector<int>& nums) {
        int n= nums.size();

        if(n< 3)return 0;
        
        vector<int> LIS(n,1);
        solve(nums,LIS,n);

        reverse(nums.begin(),nums.end());
        vector<int> LDS(n,1);
        solve(nums,LDS,n);
        reverse(LDS.begin(),LDS.end());
        
        int ans= n;
        for(int i=0; i<n; i++)
        {
            if(LIS[i] > 1 && LDS[i] > 1)
            {
                int rem= (n+1)- LIS[i]- LDS[i];
                ans= min(ans,rem);
            } 
        }
    return ans;
    }
};













// Approach 1 -> Finding LIS,LDS using nested for loops
// TC= O(N^2)

/*

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n= nums.size();

        vector<int> LIS(n,1);
        vector<int> LDS(n,1);

        // first fill Longest Increasing subsequence
        for(int i=0; i<n; i++)
        {
            for(int j=i-1; j>=0; j--)
            {
                if(nums[i] > nums[j])
                {
                   LIS[i]= max(LIS[i], 1 + LIS[j]);
                }
            }
        }

        // now fill the longest decreasing subsequence starting from end of array
        for(int i= n-1; i>=0; i--)
        {
            for(int j=i+1; j<n; j++)
            {
                if(nums[i] > nums[j])
                {
                    LDS[i]= max(LDS[i], 1 + LDS[j]);
                }
            }
        }

        // Rem elements -> (n - LIS[i] - LDS[i]) + 1     ->> Find max of all rem elements..
        // +1 added bcoz both LIS[i] and LDS[i] contains curr index i which is subtracted twice

        int ans= n;
        for(int i=0; i<n; i++)
        {
            // Mountain array should have min of 3 elements, so there should be atleast one LIS and one LDS...
            if(LIS[i] > 1 && LDS[i] > 1)
            {
               int rem= n + 1 - LIS[i] - LDS[i];
               ans= min(ans, rem);
            }
        }
    return ans;
    }
};

*/