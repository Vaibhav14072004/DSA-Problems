// Approach 1 -> DFS (Constructing the graph and immediatley checking whether we can reach u to v)
// TC= O(N* (V+E))
class Solution {
public:
    bool DFS(int u, int v, vector<bool> &visited,unordered_map<int,vector<int>> &adj)
    {
         visited[u]= true;

         if(u== v) return true;

         for(auto it: adj[u])
         {
            if(!visited[it])
            {
               if(DFS(it,v,visited,adj))
               {
                  return true;
               }
            }
         }
       return false;  
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n= edges.size();
        
        // first create adj list
        unordered_map<int,vector<int>> adj;
        for(auto it: edges)
        {
            int u= it[0];
            int v= it[1];

            vector<bool> visited(n+1,false);
            
            // if both u and v is already present in graph and we can reach u to v
            if(adj.count(u) && adj.count(v) && DFS(u,v,visited,adj))
            {
                return it;
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    return {};
    }
};