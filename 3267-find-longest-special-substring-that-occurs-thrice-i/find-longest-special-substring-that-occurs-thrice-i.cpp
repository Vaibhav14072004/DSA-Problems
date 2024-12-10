// Dhairya Kumar Singh

class Solution 
{
public:
    int maximumLength(string s) 
    {
        int n = s.size();
        vector<vector<int>> cnt(26, vector<int>(n + 1, 0));
        int l = 0, r = 0;
        while (r < n) 
        {
            if (s[l] != s[r]) 
            {
                cnt[s[l] - 'a'][r - l] += 1;
                l = r;
            }
            r += 1;
        }
        cnt[s[l] - 'a'][r - l] += 1;
        for (int j = n; j >= 1; j--) 
        {
            for (int i = 0; i < 26; i++) 
            {
                if (j + 1 <= n) cnt[i][j] += cnt[i][j + 1] * 2;
                if (cnt[i][j] >= 3) return j;
            }
        }
        return -1;
    }
};