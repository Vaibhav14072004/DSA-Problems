// Same ques as Find no of islands (No of disconnected components)

// Approach 1 -> DFS
// TC= O(V+E)

class Solution{
public:
   void DFS(int node,vector<bool> &visited,vector<vector<int>> &adj,int n)
   {
       if(visited[node]){
         return;
       }

       visited[node]= true;
       for(auto it: adj[node])
       {
          if(!visited[it]){
            DFS(it,visited,adj,n);
          }
       }
   }


  int makeConnected(int n, vector<vector<int>>& connections) 
    { 
        // base case ->> To connect n nodes, we must need n-1 edges
        if(connections.size() < n-1){
            return -1;
        }
        
        vector<bool> visited(n,false);
        vector<vector<int>> adj(n);
       
        // create adj list
        for(auto it: connections){
            int u= it[0];
            int v= it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int cnt= 0;
        for(int i=0; i<n; i++)
        {
            if(!visited[i]){
               cnt++;
               DFS(i,visited,adj,n);
            }
        }

    // if there are n disconnected components, we need n-1 edges to connect
      return cnt-1;  
    }
};







/* ---- Giving WRONG ANS (Wrong Approach) ------

   (CANNOT solve this by using same approach as Redundant Connection)
   
   Ex- n=6 and [[0,1],[0,2],[0,3],[1,2]] 
   Bcoz when we iterate and reach the last indexed val [1,2]
   we will get output as 1 bcoz it is redundant connection
   but output must be 0, bcoz there is NO disconnected component we had to make a edge and connect


// Approach 1 -> DFS 
// While making adj list, check if path from u to v already exists or NOT

// TC= O(V+E)


class Solution {
public:
    bool DFS(int u, int v, unordered_map<int,vector<int>> &adj,vector<bool> &visited)
    {
        visited[u]= true;
        
        if(u== v){
            return true;
        }

        for(auto it: adj[u])
        {
            if(!visited[it])
            {
                if(DFS(it,v,adj,visited)){
                    return true;
                }
            }
        }
    return false;
    }


    int makeConnected(int n, vector<vector<int>>& connections) 
    { 
        // base case ->> To connect n nodes, we must need n-1 edges
        if(connections.size() < n-1)
        {
            return -1;
        }

        // adj list
        unordered_map<int,vector<int>> adj;
        
        int cnt= 0;
        for(auto it: connections)
        {
            int u= it[0];
            int v= it[1];
            vector<bool> visited(n,false);

            if(adj.count(u) && adj.count(v) && DFS(u,v,adj,visited))
            {
                cnt++;
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        } 
      return cnt;
    }
};

*/