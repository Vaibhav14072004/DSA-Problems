// Approach 1 -> Top Down (Memoization)
// Tc= O(N^3)
// SC= O(N)

class Solution {
public:
    int solve(int j, int k, vector<int> &arr, vector<vector<int>> &dp, unordered_map<int,int> &mp)
    {
         if(dp[j][k] != -1)
         {
            return dp[j][k];
         }

         int target= arr[k]-arr[j];

         if(mp.count(target) && mp[target] < j){
             // 1 is added bcoz we have included k in answer..
             return 1 + solve(mp[target],j,arr,dp,mp); 
         }

        // at end of recurence call, we have to include i, j also 
      return 2;   
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int n= arr.size();
        vector<vector<int>> dp(n, vector<int> (n,-1));
        int maxLen= 0;
        
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++)
        {
            mp[arr[i]]= i;
        }
        
        //  i j k  =>> (arr[k]-arr[j]== arr[i])
        for(int j= 1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                 int len= solve(j,k,arr,dp,mp);
                 if(len >= 3)
                 {
                    maxLen= max(maxLen, len);
                 }
            }
        }
    return maxLen;  
    }
};