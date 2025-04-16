// Approach -> Using Sliding Window
// TC= O(N)

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n= nums.size();
        long long cnt= 0;
        long long pairs= 0;
        int i=0, j=0;
        
        unordered_map<int,int> mp;
        while(j < n)
        {
            pairs+= mp[nums[j]];
            mp[nums[j]]++;

            // shrink the window, until pairs >= k
            while(pairs >= k)
            {
                cnt+= (n-j);
                mp[nums[i]]--;
                pairs-= mp[nums[i]];
               i++;
            }
            j++;
        }
    return cnt;
    }
};