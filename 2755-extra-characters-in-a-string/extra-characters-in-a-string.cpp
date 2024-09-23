class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        vector<int> dp(n + 1, n); // dp[i] means the min extra chars from s[0..i-1]
        dp[0] = 0;

        for (int i = 0; i < n; ++i) {
            // Try to skip the current character
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);

            // Try to match a word in the dictionary
            for (int j = i; j < n; ++j) {
                if (dict.count(s.substr(i, j - i + 1))) {
                    dp[j + 1] = min(dp[j + 1], dp[i]);
                }
            }
        }

        return dp[n];
    }
};