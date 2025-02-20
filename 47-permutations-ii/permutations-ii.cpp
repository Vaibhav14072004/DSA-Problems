// Ques of BackTracking
// Approach 1 ->  Using freq map
// TC= O(N* N!) + O(N)
// SC= O(N* N!) + O(N)


class Solution {
public:
    void solve(vector<int> &nums,unordered_map<int,int> &mp,vector<int> &curr,vector<vector<int>> &ans)
    {
        // base case
        if(curr.size()== nums.size())
        {
            ans.push_back(curr);
            return;
        }

        for(auto it: mp)
        {
            // if freq of element is 0
            if(it.second== 0){
                continue;
            }
            curr.push_back(it.first);
            mp[it.first]--;

            solve(nums,mp,curr,ans);

            // backtrack..
            mp[it.first]++;
            curr.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> ans;
        vector<int> curr;
        unordered_map<int,int> mp;

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }

        solve(nums,mp,curr,ans);
        return ans;
    }
};