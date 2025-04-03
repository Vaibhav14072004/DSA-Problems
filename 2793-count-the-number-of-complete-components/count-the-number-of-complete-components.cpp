/*
Connected Component should have, Edges= (V)*(V-1)/2
*/


// Approach 1 -> Using DFS
// TC= O(V+E)


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