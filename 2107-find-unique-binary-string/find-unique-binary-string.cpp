// Approach 2 -> BackTracking...
// TC= O(2^N)
// SC= O(N^2) + O(N) for recursive stack space

class Solution{
public:
    void solve(vector<string> &nums, string &curr, string &ans,unordered_set<string> &st)
    {
        // base case
        if(!ans.empty()) return;

        if(curr.size()== nums.size())
        {
            if(!st.count(curr))
            {
                ans= curr;
            }
           return; 
        }
        
        // First try to append '0' and call recursion
        curr+= '0';
        solve(nums,curr,ans,st);
        curr.pop_back();
        
        // Then try to append '1' and call recursion
        curr+= '1';
        solve(nums,curr,ans,st);
        curr.pop_back();
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n= nums.size();
        string ans= "";
        string curr= "";
        unordered_set<string> st(nums.begin(),nums.end());
        solve(nums,curr,ans,st);
        return ans;
    }
};







// Optimized Best Approach 1 ->> Just put the opposite of every digit in ans
// TC= O(N)

/*

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n= nums.size();
        string ans= "";
        
        for(int i=0;i<n;i++)
        {
            if(nums[i][i]== '0')
            {
                ans+= '1';
            }
            else
            {
                ans+= '0';
            }
        }
    return ans;
    }
};

*/