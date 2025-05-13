class Solution {
public:
    const int MOD = 1e9 + 7;
    int findLen(char c, int t, vector<vector<int>> &dp){
        if(dp[c - 'a'][t] != -1)
            return dp[c - 'a'][t];
        int transToZ = 'z' - c;
        if(t <= transToZ)
            return dp[c - 'a'][t] = 1;
        return dp[c - 'a'][t] = (findLen('a', t - transToZ - 1, dp) + findLen('b', t - transToZ - 1, dp))%MOD;
    }
    int lengthAfterTransformations(string s, int t) {
        int n = 0;
        vector<vector<int>> dp(26, vector<int>(t+1, -1));
        for(char c: s){
            n = (n + findLen(c, t, dp))%MOD;
        }
        return n;
    }
};