class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();
        vector dp(n, vector(m, vector<int>(3, -1e9)));
        dp[0][0][1] = dp[0][0][2] = 0, dp[0][0][0] = coins[0][0];
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < 3; k++) {
                    if (i) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + coins[i][j]);
                    if (i && k) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1]);
                    if (j) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + coins[i][j]);
                    if (j && k) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1]);
                }
        int ans = *max_element(dp[n - 1][m - 1].begin(), dp[n - 1][m - 1].end());
        return ans;
    }
};





// class Solution {
// public:
//     void dfs(int i, int j, priority_queue<int> pq, int profit, int& maxProfit, vector<vector<int>>& coins, int n, int m) {

//         // if destination is reached..
//         if (i == n - 1 && j == n - 1)
//         {
//             if (coins[i][j] < 0) {
//                 pq.push(abs(coins[i][j]));
//             }

//             if (!pq.empty()) {
//                 profit += pq.top();
//                 maxProfit= max(maxProfit,profit);
//                 pq.pop();
//             }

//             if (!pq.empty()) {
//                 profit += pq.top();
//                 maxProfit= max(maxProfit,profit);
//                 pq.pop();
//             }
//             return;
//         }

//         // moving down...
//         if (i + 1 < n) 
//         {
//             priority_queue<int> newPq= pq;
//             if (coins[i + 1][j] < 0) {
//                 newPq.push(abs(coins[i + 1][j]));
//             }
//             dfs(i + 1, j, newPq, profit, maxProfit,coins, n, m);
//         }

//         // moving right....
//         if (j + 1 < m) 
//         {
//             priority_queue<int> newPq= pq;
//             if (coins[i][j + 1] < 0) {
//                 newPq.push(abs(coins[i][j + 1]));
//             }
//             dfs(i, j + 1, newPq, profit, maxProfit, coins, n, m);
//         }
//     }

//     int maximumAmount(vector<vector<int>>& coins) {
//         int n = coins.size();
//         int m = coins[0].size();
//         priority_queue<int> pq;

//         int profit = 0, maxProfit= 0;
//         dfs(0, 0, pq, profit, maxProfit,coins, n, m);
//         return maxProfit;
//     }
// };




