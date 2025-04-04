/*
Connected Component should have, Edges= (V)*(V-1)/2
*/

// Aproach 2 -> Using BFS
// TC= O(V+E)

class Solution{
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) 
    {
        // adj list 
        unordered_map<int,vector<int>> adj;
        for(auto it: edges){
            int u= it[0];
            int v= it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n,false);
        int cnt= 0;

        for(int i=0; i<n; i++)
        {
            if(!visited[i]){
                queue<int> q;
                q.push(i);
                visited[i]= true;

                int vertices= 0;
                int edges= 0;

                while(!q.empty())
                {
                   int node= q.front();
                   q.pop();
                   visited[node]= true;
                   vertices++;
                   edges+= adj[node].size();

                   // now check for its neighbours...
                   for(auto it: adj[node])
                   {
                       if(!visited[it])
                       {
                           visited[it]= true;
                           q.push(it);
                       }
                   }
                }
                
                // edges must be equal to (v)*(v-1)/2 but here edges are counted twice
                if(edges== (vertices)*(vertices-1))
                   cnt++;
            }
        }
    return cnt;
    }
};





// Approach 1 -> Using DFS
// TC= O(V+E)

/*

class Solution {
public:
    void DFS(int node, vector<bool> &visited, unordered_map<int,vector<int>> &adj, int &vertices, int &edges)
    {
        visited[node]= true;
        vertices++;
        edges+= adj[node].size();  // each edges will be counted twice here

        for(auto it: adj[node])
        {
            if(!visited[it]){
              DFS(it,visited,adj,vertices,edges);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) 
    {
        int cnt= 0;
        unordered_map<int,vector<int>> adj;
        for(auto it: edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> visited(n,false);
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                int vertices= 0, edges= 0;
                DFS(i,visited,adj,vertices,edges);
                
                // if it is connected component, then no of edges must be (v)(v-1)/2
                // bcoz edges are counted twice, so we divided by edges/2== (v)(v-1)/2
                if(edges== vertices*(vertices-1))
                {
                    cnt++;
                }
            }
        }
    return cnt;
    }
};

*/