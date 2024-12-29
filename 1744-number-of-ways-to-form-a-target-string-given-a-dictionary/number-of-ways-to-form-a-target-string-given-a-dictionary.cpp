// Approach 1 -> Top Down (Recursion + Memoization)
// TC= O[(Len of each word)* Len of target] 
// TC= O(W* T)

class Solution {
public:
    const int MOD= 1000000007;

    int solve(int i, int j, vector<string> &words,string &target, vector<vector<long long>> &freq, vector<vector<int>> &dp)
    {
        int w= words[0].size();
        int t= target.size();
        
        // if target got finished.. return 1
        if(j== t){
          return 1;
        }
        
        if(i== w)
        {
          return 0;
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        // If we take the curr index, we can have freq[i] possibilities to start..
        int take= (freq[target[j]- 'a'][i] * solve(i+1,j+1,words,target,freq,dp)) % MOD;
    
        int NOTake= solve(i+1,j,words,target,freq,dp) % MOD;

     return dp[i][j]= (take+ NOTake)% MOD;
    }  

    int numWays(vector<string>& words, string target) {
        int w= words[0].size();
        int t= target.length();

        vector<vector<long long>> freq(26, vector<long long> (w,0));
        
        for(int col=0; col<words[0].size(); col++)
        {
            for(string &word: words)
            {
                char ch= word[col];
                freq[ch- 'a'][col]++;
            }
        }

        vector<vector<int>> dp(w+1, vector<int> (t+1,-1));
        return solve(0,0,words,target,freq,dp);
    }
};