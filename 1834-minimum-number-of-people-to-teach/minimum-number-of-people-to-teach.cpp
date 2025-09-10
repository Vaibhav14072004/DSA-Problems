class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size(); // number of people

        // store bitset of languages each person knows
        vector<bitset<501>> mp(m);
        for (int i = 0; i < m; i++) {
            for (int lang : languages[i]) {
                mp[i].set(lang);  // mark language as known
            }
        }

        // find all people who cannot communicate
        unordered_set<int> needTeach;
        for (auto &f : friendships) {
            int a = f[0] - 1, b = f[1] - 1;
            if ((mp[a] & mp[b]).none()) {   // no common language
                needTeach.insert(a);
                needTeach.insert(b);
            }
        }

        if (needTeach.empty()) return 0;

        // now check for each language how many already know it
        int ans = INT_MAX;
        for (int lang = 1; lang <= n; lang++) {
            int cnt = 0;
            for (int person : needTeach) {
                if (mp[person].test(lang)) cnt++;
            }
            ans = min(ans, (int)needTeach.size() - cnt);
        }

        return ans;
    }
};