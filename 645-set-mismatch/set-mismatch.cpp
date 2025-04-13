// Approach 1 -> Using unordered_map
// TC= O(N)

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n= nums.size();
        int repeat= -1, missing= -1;
        unordered_map<int,int> mp;

        for(int i=0; i<n; i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]== 2)
            {
                repeat= nums[i];
            }
        }

        for(int i=1; i<=n; i++)
        {
            if(mp[i]== 0)
            {
                missing= i;
            }
        }
    return {repeat, missing};
    }
};