// Approach 2 -> Using unordered_set
// TC= O(N)

class Solution{
  public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n= nums.size();
        unordered_set<int> st;
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            if(st.count(nums[i]))
            {
                ans.push_back(nums[i]);
            }
            st.insert(nums[i]);
        }
      return ans;  
    }
};





// Approach 1 -> Using unordered_map
// TC= O(N)

/*

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n= nums.size();

        unordered_map<int,int> mp;
        vector<int> ans;
        
        for(int i=0; i<n; i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]] > 1)
            {
                ans.push_back(nums[i]);
            }
        }
       return ans; 
    }
};

*/