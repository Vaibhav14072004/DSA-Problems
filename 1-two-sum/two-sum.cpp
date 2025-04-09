// Appraoch 2 -> using unordered_map
// TC= O(N)

class Solution{
public:
  vector<int> twoSum(vector<int> &nums,int target)
  {
      int n= nums.size();

      // value, index
      unordered_map<int,int> mp;

      for(int i=0; i<n; i++)
      {
          if(mp.find(target-nums[i]) != mp.end())
          {
             return {i, mp[target-nums[i]]};
          }
          mp[nums[i]]= i;
      }
    return {};
  }
};






// Approach 1 -> Brute Force Approach 
// Generate all subarrays

// TC= O(N^2)

/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n= nums.size();

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(nums[i]+nums[j]== target)
                {
                    return {i,j};
                }
            }
        }
       return {}; 
    }
};

*/