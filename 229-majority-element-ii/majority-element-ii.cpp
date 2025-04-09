// Approach 1 -> Using unordered_map
// TC= O(N)
// SC= O(N)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int,int> mp;
        int needed= n/3;
        vector<int> ans;

        for(int i=0; i<n; i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]] > needed)
            {
                if(ans.empty())
                {
                    ans.push_back(nums[i]);
                }
                else if(ans.back() != nums[i])
                {
                    ans.push_back(nums[i]);
                }

                if(ans.size()== 2)
                {
                    break;
                }
            }
        }
        return ans;
    }
};