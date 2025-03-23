class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long, long long>> adj[n];
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        pq.push({0, 0});
        vector<long long> dist(n, LONG_MAX);
        dist[0] = 0;
        vector<long long> ways(n, 0);
        ways[0] = 1;
        long long mod = 1e9 + 7;
        while (!pq.empty()) {
            auto it = pq.top();
            long long node = it.second;
            long long dis = it.first;
            pq.pop();

            for (auto it : adj[node]) {
                long long edjnode = it.first;
                long long edjwt = it.second;
                if (edjwt + dis < dist[edjnode]) {
                    dist[edjnode] = edjwt + dis;
                    pq.push({dist[edjnode], edjnode});
                    ways[edjnode] = ways[node];
                } else if (dis + edjwt == dist[edjnode]) {
                    ways[edjnode] = (ways[edjnode] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};