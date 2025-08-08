class Solution {
private:
    double solve(int n, int m, unordered_map<int,unordered_map<int, double>>&dp)
    {
        if(n <= 0 && m > 0)
        return 1;

        if(n <= 0 && m <= 0)
        return 0.5;

        if(m <= 0)
        return 0;

        if(dp[n][m] > 0)
        return dp[n][m];

        double one = solve(n-100, m, dp);
        double two = solve(n-75, m-25, dp);
        double three = solve(n-50, m-50, dp);
        double four = solve(n-25, m-75, dp);

        return dp[n][m] = 0.25*(one + two + three + four);
    }
public:
    double soupServings(int n) {
        if(n >= 4800)
        return 1;
        unordered_map<int,unordered_map<int, double>>dp;
        return solve(n, n, dp);
    }
};