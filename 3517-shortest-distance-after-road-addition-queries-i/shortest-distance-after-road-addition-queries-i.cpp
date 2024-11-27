// Approach 2 -> Using Dijsktra
// TC= O(q* E *log V)

class Solution {
public:
    int dijsktra(int n, unordered_map<int, vector<pair<int,int>>> & adj)
    {
        // Min heap ->> {dist,node}
         priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        // dist[i] ->> means shortest dist from source node to (i)th node
         vector<int> shortestDist(n,INT_MAX);

         pq.push({0,0});
         shortestDist[0]= 0;

         while(!pq.empty())
         {
            int dist= pq.top().first;
            int node= pq.top().second;
            pq.pop();

            if(node== n-1)
            {
                return shortestDist[n-1];
            }

            for(auto it: adj[node])
            {
                int neighbour= it.first;
               int wt= it.second;
               if(dist + wt < shortestDist[neighbour])
               {
                   shortestDist[neighbour]= dist+ wt;
                   pq.push({dist+wt, neighbour});
               }
            }
         }
    return -1;
    }


    vector<int> shortestDistanceAfterQueries(int n,vector<vector<int>>& queries) {
        vector<int> ans;
        unordered_map<int, vector<pair<int,int>>> adj;
        
        // Adjacent nodes are at a dist of 1 with each other
        for (int i = 1; i < n; i++)
        {
            adj[i - 1].push_back({i,1});
        }

        for (auto it : queries) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back({v,1});

            int shortestDist = dijsktra(n, adj);
            ans.push_back(shortestDist);
        }
        return ans;
    }
};








// Approach 1 -> BFS
// TC= O[q* (V+E)]

/*

class Solution {
public:
    int BFS(int n, unordered_map<int, vector<int>>& adj)
    {
        vector<int> visited(n,0);
        int level= 0;
        queue<int> q;
        q.push(0);
        visited[0]= 1;

        while(!q.empty())
        {
            int len= q.size();
            while(len--)
            {
                int front= q.front();
                q.pop();

                if(front== n-1)
                {
                    return level;
                }

                for(auto neighbour: adj[front])
                {
                    if(!visited[neighbour])
                    {
                        visited[neighbour]= 1;
                        q.push(neighbour);
                    }
                }
            }
            level++;
        }
     return -1;
    }


    vector<int> shortestDistanceAfterQueries(int n,vector<vector<int>>& queries){
         vector<int> ans; 
         unordered_map<int, vector<int>> adj;

        for (int i = 1; i < n; i++) {
            adj[i - 1].push_back(i);
        }

        for (auto it : queries) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);

            int shortestDist = BFS(n, adj);
            ans.push_back(shortestDist);
        }
        return ans;
    }
};

*/