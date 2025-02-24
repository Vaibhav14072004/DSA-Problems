class Solution {

    bool getBobPath(int node, int timeStamp, vector<vector<int>> &adj, vector<int> &bobPath, vector<bool> &vis)
    {
        vis[node] = true;
        bobPath[node] = timeStamp;

        if(node == 0) {
            return true;
        }

        for(int i = 0; i < adj[node].size(); i++) {
            if(!vis[adj[node][i]]) {

                if(getBobPath(adj[node][i], timeStamp + 1, adj, bobPath, vis)) {
                    return true;
                }
            }
        }

        vis[node] = false;
        bobPath[node] = -1;

        return false;
    }

    int getAliceScore(int node, int currScore, vector<int> &bobPath, vector<vector<int>> &adj, int timeStamp, vector<int>& amount, vector<bool> &vis) 
    {
        vis[node] = true;

        
        if(bobPath[node] == timeStamp)
        {
            currScore += amount[node] / 2;
        }

        if(bobPath[node] == -1 || bobPath[node] > timeStamp) {
            currScore += amount[node];
        }

        if(adj[node].size() == 1 && node != 0) return currScore;

        int maxScore = INT_MIN;

        for(int i = 0; i < adj[node].size(); i++) {
            if(!vis[adj[node][i]]) {
                maxScore = max(maxScore, getAliceScore(adj[node][i], currScore, bobPath, adj, timeStamp + 1, amount,  vis));
            }
        }

        vis[node] = false;
        return maxScore;
    }

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        
        int n = edges.size();

        vector<vector<int>> adj(n + 1);

        for(int i = 0; i < n; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> bobPath(n + 1, -1);
        vector<bool> vis(n + 1,  false);
        vector<bool> vis1(n + 1, false);

        getBobPath(bob, 0, adj, bobPath,vis);

        int ans =  getAliceScore(0, 0, bobPath, adj, 0, amount, vis1);

        return ans;
    }
};