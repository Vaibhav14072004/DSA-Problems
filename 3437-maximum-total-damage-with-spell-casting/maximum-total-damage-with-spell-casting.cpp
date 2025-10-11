class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(), power.end());
        int n = power.size();
        vector<long long> dp(n*2, 0);
        for (int i = 0; i < n; i++) {
            dp[i*2 + 1] = power[i];
            dp[i*2] = 0;
            if (i > 0)
                dp[i*2] = max(dp[(i-1)*2], dp[(i-1)*2 + 1]); // 不选择当前位置
            for (int j = 1; j <=  i; j++)  {
                if (power[i] - power[i-j] > 2) {
                    dp[i*2 + 1] = max( dp[i*2 + 1], max(dp[(i-j)*2], dp[(i-j)*2 + 1]) + power[i]);
                    break;
                }
            }
            int j = i+1;
            while (j < n && power[j] == power[i])
            {
                dp[j*2 + 1] = dp[(j-1)*2+1] + power[j];
                dp[j*2] = dp[(j-1)*2];
                // printf("i=%d, dp[j*2 + 1]=%lld, dp[(j-1)*2+1]=%lld\n", i,  dp[j*2 + 1] , dp[(j-1)*2+1]);

                j++;

            }
            i = j-1;
            // printf("i=%d, dp[i*2+1]=%lld, dp[i*2]=%lld\n", i, dp[i*2+1], dp[i*2]);
        }
        return max(dp[2*n-1], dp[2*n-2]);
    }
};