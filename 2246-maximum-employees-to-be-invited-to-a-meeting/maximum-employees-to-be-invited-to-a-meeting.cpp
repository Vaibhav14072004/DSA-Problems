class Solution {
    int f(const vector<vector<int>>& p, vector<int>& visited, int v) {
        visited[v] = 1;
        int ans = 0;
        for (int i : p[v]) {
            ans = max(ans, f(p, visited, i));
        }
        return ans + 1;
    }
    int c(const vector<int>& adj, const vector<vector<int>>& p, vector<int>& visited, int start) {
        int depth = 1;
        int prev = start;
        int cur = adj[prev];
        while (!visited[cur]) {
            visited[cur] = depth++;
            prev = cur;
            cur = adj[cur];
        }
        int ans = visited[prev] - visited[cur] + 1;
        // visit entire graph
        for (int i = 0; i < ans; ++i) {
            for (int j : p[cur]) {
                if (j != prev) {
                    f(p, visited, j);
                }
            }
            prev = cur;
            cur = adj[cur];
        }
        return ans;
    }
public:
    int maximumInvitations(vector<int>& adj) {
        const int s = adj.size();
        vector<int> visited(s, 0);
        vector<vector<int>> p(s);
        for (int i = 0; i < s; ++i) {
            p[adj[i]].push_back(i);
        }
        int sum_depths = 0;
        for (int i = 0; i < s; ++i) {
            if (!visited[i]) {
                if (i == adj[adj[i]]) {
                    visited[i] = 1;
                    visited[adj[i]] = 1;
                    int sr1 = 0;
                    for (int j : p[i]) {
                        if (j == adj[i]) {
                            continue ;
                        }
                        sr1 = max(sr1, f(p, visited, j));
                    }
                    int sr2 = 0;
                    for (int j : p[adj[i]]) {
                        if (j == i) {
                            continue ;
                        }
                        sr2 = max(sr2, f(p, visited, j));
                    }
                    sum_depths += sr1 + sr2 + 2;
                }
            }
        }
        int max_circle = 0;
        for (int i = 0; i < s; ++i) {
            if (!visited[i]) {
                max_circle = max(max_circle, c(adj, p, visited, i));
            }
        }
        return max(sum_depths, max_circle);
    }
};