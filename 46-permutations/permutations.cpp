// Approach 1 -> Generating and Storing all permutations
// TC= O(N* N!)
// SC= O(N* N!) + O(N)

class Solution {
public:
    void solve(vector<int> &nums,vector<int> &curr,vector<vector<int>> &ans, vector<bool> &used)
    {
        // base case
        if(curr.size()== nums.size())
        {
            ans.push_back(curr);
            return;
        }
        
        // here order does not matters, [1,2,3] m 1 can come even after 2
        for(int j=0; j<nums.size(); j++)
        {
            if(used[j]) {
               continue;
            }
            
            used[j]= true;
            curr.push_back(nums[j]);
            solve(nums,curr,ans,used);

            // backtarcking...
            used[j]= false;
            curr.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> used(n,false);

        solve(nums,curr,ans,used);
        return ans;
    }
};