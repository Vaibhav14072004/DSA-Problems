// Approach ->> Dijsktra Algorithm
// TC= O(E* log V)

class Solution {
public:
    const int MOD= 1000000007;

    int countPaths(int n, vector<vector<int>>& roads) {

        // adj list ->> {u, {v,time}}
        unordered_map<int,vector<pair<int,int>>> adj;

        for(int i=0; i<roads.size(); i++)
        {
            int u= roads[i][0];
            int v= roads[i][1];
            int dist= roads[i][2];

            adj[u].push_back({v,dist});
            adj[v].push_back({u,dist});
        }
        
        // min heap ->> {shortestTime, node}  ... shortestTime must be long long
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0,0});

        vector<long long> minTime(n,LLONG_MAX);
        minTime[0]= 0;
        
        // total no of ways to reach that node
        vector<int> ways(n,0);
        ways[0]= 1;

        while(!pq.empty())
        {
            long long currTime= pq.top().first;
            int currNode= pq.top().second;
            pq.pop();

            for(auto it: adj[currNode])
            {
                int neighbour= it.first;
                int time= it.second;

                if(currTime+ time < minTime[neighbour])
                {
                    minTime[neighbour]= currTime+ time;
                    pq.push({currTime+time, neighbour});
                    ways[neighbour]= ways[currNode];
                }

                // there is one more way to reach that node..
                else if(currTime+ time == minTime[neighbour])
                {
                    ways[neighbour]= (ways[neighbour]+ ways[currNode]) % MOD;
                }
            }
        }
    return ways[n-1];
    }
};