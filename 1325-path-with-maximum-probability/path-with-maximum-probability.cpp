/*
    ---- Same concept as Dijsktra Algorithm ----
   1. But instead of min dist, we have to find max prob
   2. prob[src]= 1 (bcoz khud se khud ki prob is always 1 ) insead of dist[src]= 0
*/

// TC= O[(V+E)* log V]

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, 
    int start_node, int end_node)
    {
        // first create adj list... for undirected graph..
        vector<vector<pair<int,double>>> adjList(n);

        for(int i=0; i<edges.size(); i++)
        {
            int u= edges[i][0];
            int v= edges[i][1];
            double prob= succProb[i];

            adjList[u].push_back({v,prob});
            adjList[v].push_back({u,prob});
        }

        // max heap to get max element at top ->> storing {prob, node}
        priority_queue<pair<double,int>> pq;   

        vector<double> prob(n, 0.0);
        prob[start_node]= 1.0;

        // khud se khud p jaane ki probability is always 1
        pq.push({1.0,start_node});

        while(!pq.empty())
        {
            double currProb= pq.top().first;
            int currNode= pq.top().second;
            pq.pop();

            for(auto it: adjList[currNode])
            {
                int neighbour= it.first;
                double neighbourProb= it.second;

                if(prob[neighbour] < neighbourProb* currProb)
                {
                    prob[neighbour]= neighbourProb* currProb;
                    pq.push({prob[neighbour], neighbour});
                }
            }
        }

        return prob[end_node];
    }
};