class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, 0);
        long long maxPoints = 0;

        for (int i = n - 1; i >= 0; --i) {
            long long points = questions[i][0];
            int brainpower = questions[i][1];

            dp[i] = points;
            if (i + brainpower + 1 < n) {
                dp[i] += dp[i + brainpower + 1];
            }

            if (i + 1 < n) {
                dp[i] = max(dp[i], dp[i + 1]);
            }

            maxPoints = max(maxPoints, dp[i]);
        }

        return maxPoints;
    }
};