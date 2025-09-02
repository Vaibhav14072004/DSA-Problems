class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<int> dp(n);
        std::unordered_map<int, std::vector<int>> mp; // renamed here
        for (int i = 0; i < offers.size(); ++i) {
            mp[offers[i][1]].push_back(i); // use mp instead of offersByEnd
        }

        int best = 0;
        for (int i = 0; i < n; ++i) {
            for (int offerId : mp[i]) { // changed to mp
                int lastNoConflict = offers[offerId][0] - 1;
                int select = offers[offerId][2];
                if (lastNoConflict >= 0) {
                    select += dp[lastNoConflict];
                }
                best = max(best, select);
                dp[i] = max(dp[i], best);
            }
            dp[i] = best;
        }
        return best;
    }
};
