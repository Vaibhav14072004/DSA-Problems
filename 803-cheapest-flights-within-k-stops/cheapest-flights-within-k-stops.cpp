/*
Dijkstra will consider only that path which have MIN distance but it will NOT take 
account of max K stops...  =>> { dist, {node, stops}} => Will NOT BE TAKEN

So we will give preference to [No of Stops(K)] NOT to min dist
{ Stops, {node, dist}} => Will be TAKEN

Also NO NEED of priority_queue just take simple queue bcoz stops are increasing by 1 
only... always Lowest Stops wala bw taken out from queue...
*/

// TC of Dijsktra ALgorithm is O(E* log V)

// We are NOT using priority_queue, using only simple queue
// Overall TC= O(E) ->> O(flights.size())

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it: flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }

        // {stops, {node, dist}}
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});

        vector<int> minDist(n,INT_MAX);
        minDist[src]= 0;

        while(!q.empty())
        {
            int stops= q.front().first;
            int node= q.front().second.first;
            int dist= q.front().second.second;
            q.pop();
            
            if(stops > k) continue;

            for(auto it: adj[node])
            {
                int neighbour= it.first;
                int wt= it.second;
                
                if(dist+ wt < minDist[neighbour] && stops <= k)
                {
                    minDist[neighbour]= dist+wt;
                    q.push({1+stops, {neighbour, dist+wt}});
                }
            }
        }
    
    if(minDist[dst]== INT_MAX) return -1;

    return minDist[dst];
    }
};