// Approach 2 -> Using unordered_map
// TC= O(2*N)

class Solution{
public:
   int findLHS(vector<int> &nums)
   {
      int n= nums.size();
      unordered_map<int,int> mp;

      for(int i=0; i<n; i++)
      {
         mp[nums[i]]++;
      }

      int maxi= 0;
      for(auto it: mp)
      {
          int temp= it.second;
          if(mp.count(it.first+1))
          {
              maxi= max(maxi, temp+ mp[it.first+1]);
          }
      }
    return maxi;  
   }
};






// Approach 1 ->> Sorting + 2 loops
// TC= O(N*log N)+ O(N)

/*

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, maxLen = 0;

        for (int j = 0; j < nums.size(); ++j) {
            while (nums[j] - nums[i] > 1) {
                i++;
            }

            if (nums[j] - nums[i] == 1) {
                maxLen = max(maxLen, j - i + 1);
            }
        }

        return maxLen;
    }
};

*/