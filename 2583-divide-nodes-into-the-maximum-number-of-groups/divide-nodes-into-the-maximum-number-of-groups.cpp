class Solution {
public:
    int n;
    vector<vector<int>> adj;
    vector<int> color;
    vector<bool> visited;

    // Constructor to initialize graph
    void initialize(int nodes, vector<vector<int>>& edges) {
        n = nodes;
        adj.resize(n + 1);
        color.assign(n + 1, -1);
        visited.assign(n + 1, false);

        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
    }

    // Function to check if a component is bipartite
    bool isBipartite(int node, vector<int>& component) {
        queue<int> q;
        q.push(node);
        color[node] = 0;
        component.push_back(node);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                    component.push_back(v);
                } else if (color[v] == color[u]) {
                    return false; // Odd cycle found, not bipartite
                }
            }
        }
        return true;
    }

    // Function to compute max depth using BFS
    int bfsMaxDepth(int start) {
        queue<int> q;
        vector<int> dist(n + 1, -1);
        q.push(start);
        dist[start] = 0;
        int maxDepth = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            maxDepth = max(maxDepth, dist[u]);

            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return maxDepth + 1;
    }

    int magnificentSets(int nodes, vector<vector<int>>& edges) {
        initialize(nodes, edges);

        int totalGroups = 0;

        for (int i = 1; i <= n; i++) {
            if (visited[i]) continue;

            vector<int> component;
            if (!isBipartite(i, component)) return -1;

            for (int node : component) visited[node] = true;

            int maxGroups = 0;
            for (int node : component) {
                maxGroups = max(maxGroups, bfsMaxDepth(node));
            }
            totalGroups += maxGroups;
        }

        return totalGroups;
    }
};