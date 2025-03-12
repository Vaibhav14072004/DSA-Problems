// Approach 2 -> Using Disjoint Set Union (DSU) 
// TC of DSU is O[alpha (n)]

// Overall TC= O[N* alpha(N)]

class DSU{
public:
   vector<int> parent;
   vector<int> rank;

   DSU(int n)
   {
       parent.resize(n+1);
       rank.resize(n+1, 0);

       for(int i=1; i<=n; i++)
       {
          parent[i]= i;
       }
   }

   int findParent(int node)
   {
       if(node== parent[node])
       {
           return node;
       }
       return parent[node]= findParent(parent[node]);
   }

   void Union(int u, int v)
   {
       int parent_u= findParent(u);
       int parent_v= findParent(v);

       if(parent_u== parent_v){
          return;
       }

       if(rank[parent_u] > rank[parent_v])
       {
           parent[parent_v]= parent_u;
       }
       else if(rank[parent_u] < rank[parent_v])
       {
           parent[parent_u]= parent_v;
       }
       else
       {
           parent[parent_u]= parent_v;
           rank[parent_v]++;
       }
   }
};

class Solution{
public:
   vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n= edges.size();

        DSU dsu(n);
        for(auto it: edges)
        {
            int u= it[0];
            int v= it[1];
            if(dsu.findParent(u)== dsu.findParent(v))
            {
                return it;
            }
            dsu.Union(u,v);
        }
    return {};
   } 
};





// Approach 1 -> DFS (Constructing the graph and immediatley checking whether we can reach u to v)
// TC= O(N* (V+E))

/*

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

*/