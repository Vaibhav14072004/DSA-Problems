// Approach 2 -> Optimized
// Using Sorting + Binary Search

// TC= O(N log N)

class Solution{
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n= nums.size();
        int i=0, j= n-1; 
        
        // why we have to not store original index bcoz
        // if 4,7 is >= upper then 7,4 is also >= upper, hence index NOT matters
        sort(nums.begin(), nums.end());
        long long ans= 0;

        for(int i=0; i<n; i++)
        {
            // other element should be >= (lower-nums[i])
            // so we apply lower bound to find first >= element's index
            int lowerTarget= lower- nums[i];
            
            int lowerIdx= lower_bound(nums.begin()+i+1, nums.end(), lowerTarget)- nums.begin();
                    
            // other element should be <= (upper-nums[i])
            // so we apply upper bound to find first > element's index 

            int greaterTarget= upper- nums[i];
            
            int upperIdx= upper_bound(nums.begin()+i+1, nums.end(),greaterTarget)- nums.begin();

            ans+= upperIdx-lowerIdx;
        }
    return ans;
    }
};








// Approach 1 -> Brute Force Approach => 2 Pointers
// TC= O(N^2)

/*

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n= nums.size();
        int i=0, j= n-1;

        int ans= 0;
        while(j >= 0)
        {
            int i=0;
           while(i<j)
           {  
               if(nums[i]+nums[j] >= lower && nums[i]+nums[j] <= upper)
               {
                    ans++;
               }
               i++;
           }
           j--;
        }
    return ans;
    }
};

*/