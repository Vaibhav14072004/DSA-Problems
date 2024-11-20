class Solution {
public:
    int takeCharacters(string& s, int& k) {
        if (k == 0) return 0;
        vector<int> fre(3);
        for (char& c : s) fre[c - 'a']++;
        if (fre[0] < k || fre[1] < k || fre[2] < k) return -1;

        int n = s.size(), ans = n, p2 = 0, p1 = 0;

        while (p2 < n) {
            fre[s[p2] - 'a']--;

            while (fre[s[p2] - 'a'] < k) fre[s[p1++] - 'a']++;

            ans = min(ans, n - (p2 - p1 + 1));
            p2++;
        }
        return ans;
    }
};