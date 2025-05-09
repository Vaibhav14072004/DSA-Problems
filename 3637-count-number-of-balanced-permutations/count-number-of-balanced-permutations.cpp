class Solution {
    const int MOD = 1e9 + 7;
    int dfs(int i, int balance, int oddPosCount, vector<vector<vector<int>>> &memo, vector<vector<int>> &nCr, vector<int> &freq, vector<int> &totalPos) {
        if(oddPosCount < 0 || balance < 0 || totalPos[i] < oddPosCount) {
            return 0;
        }
        if(i > 9) {
            return balance == 0 && oddPosCount == 0;
        }
        if(memo[i][balance][oddPosCount] != -1) return memo[i][balance][oddPosCount];
        int evenPosCount = totalPos[i] - oddPosCount, ans = 0;
        for(int j = max(0, freq[i] - evenPosCount); j <= min(freq[i], oddPosCount); j++) {
            int ways = (nCr[oddPosCount][j] * 1LL * nCr[evenPosCount][freq[i] - j]) % MOD;
            ans = (ans + (ways * 1LL * dfs(i + 1, balance - i * j, oddPosCount - j, memo, nCr, freq, totalPos)) % MOD) % MOD;
        }
        return memo[i][balance][oddPosCount] = ans;
    }
public:
    int countBalancedPermutations(string num) {
        int n = num.size(), total = 0;
        vector<int> freq(10);
        for(int i = 0; i < n; i++) {
            int digit = num[i] - '0';
            freq[digit]++;
            total += digit;
        }
        if(total % 2) return 0;
        int balance = total / 2;
        int oddPosCount = (n + 1) / 2;
        vector<vector<int>> nCr(oddPosCount + 1, vector<int>(oddPosCount + 1));
        nCr[0][0] = 1;
        for(int i = 1; i <= oddPosCount; i++) {
            nCr[i][0] = 1; 
            for(int j = 1; j <= i; j++) {
                nCr[i][j] = (nCr[i - 1][j] + nCr[i - 1][j - 1]) % MOD;
            }
        }
        vector<int> totalPos(11);
        for(int i = 9; i >= 0; i--) {
            totalPos[i] = totalPos[i + 1] + freq[i];
        }
        vector<vector<vector<int>>> memo(10, vector<vector<int>>(balance + 1, vector<int>(oddPosCount + 1, -1)));
        return dfs(0, balance, oddPosCount, memo, nCr, freq, totalPos);
    }
};