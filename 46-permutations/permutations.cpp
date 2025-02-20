// Approach 2 -> Using Swap function, Inplace algorithm without using separate curr string
// TC= O(N* N!)
// SC= O(N* N!) + O(N) for recursive stack

class Solution {
public:
    void solve(int idx,vector<int> &nums,vector<vector<int>> &ans)
    {
        // base case
        if(idx >= nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        // if we start loop from i=0, we will got same already used vectors again and again
        for(int i= idx; i<nums.size(); i++)
        {
            swap(nums[i],nums[idx]);
            solve(idx+1,nums,ans);
            
            // backtrack..
            swap(nums[i],nums[idx]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> ans;
        solve(0,nums,ans);
        return ans;
    }
};





// Approach 1 -> Generating and Storing all permutations
// TC= O(N* N!)
// SC= O(N* N!) + O(N) for recursive stack space

/*
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
        
        // here order does not matters, In [1,2,3], 1 can come even after 2
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

*/