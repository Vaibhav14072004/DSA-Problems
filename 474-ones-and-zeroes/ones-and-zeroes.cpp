class Solution {
public:
    int solve(vector<int> &zeroes ,vector<int> &ones , int idx ,int m , int n ,vector<vector<vector<int>>> &dp)
    {
        if(idx == zeroes.size())
        {
            return 0;
            // not checking  m ==  0 and n ==  0 because the question says at most so not necesarry you have to take all m ,n
            // and m , n can not go -ive cause i have a condition to check and assuer m , n cannot go -ive  
        } 

        int take = INT_MIN;
        if(dp[idx][m][n] != -1)
        {
            return dp[idx][m][n];
        }
        if(m >= zeroes[idx] && n >= ones[idx])
        {
            take = 1 + solve(zeroes, ones ,idx+1 , m -zeroes[idx], n - ones[idx] ,dp);
        }
        int notTake = solve(zeroes , ones ,idx+1 , m , n , dp);

        return dp[idx][m][n] = max(take , notTake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<int> ones (strs.size() , 0);
        vector<int> zeroes (strs.size() , 0);
        for(int i = 0 ; i < strs.size() ; i++)
        {
            int z = 0;
            int o = 0;
            for(int j = 0 ; j < strs[i].size(); j++)
            {
                if(strs[i][j] - '0' == 0)
                {
                    z++;
                }
                else
                {
                    o++;
                }
            }
            zeroes[i] = z;
            ones[i] = o;
        }
        vector<vector<vector<int>>> dp(strs.size() , vector<vector<int>>(m+1 , vector<int> (n+1 ,-1)));
        return solve(zeroes , ones , 0 , m , n,dp);
    }
};