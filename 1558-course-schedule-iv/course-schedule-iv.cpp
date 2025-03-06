// Approach 1 ->> Create adj list and using DFS find whether path from src to dest exists or NOT
// TC= O[q* (V+E)] + O(E)
// SC= O(V+E)

class Solution {
public:
    bool DFS(int src, int dest,vector<bool> &visited,vector<vector<int>> &adj)
    {
        visited[src]= true;
        if(src== dest){
            return true;
        }

        for(auto it: adj[src])
        {
            if(!visited[it])
            {
                if(DFS(it,dest,visited,adj))
                {
                    return true;
                }
            }
        }
     return false;   
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int q= queries.size();

        // create adj list..  (a,b) => a-> b
        vector<vector<int>> adj(numCourses);
        for(auto it: prerequisites)
        {
            adj[it[0]].push_back(it[1]);
        }
        
        vector<bool> ans(q,false);
        for(int i=0; i<q; i++)
        {
            int src= queries[i][0];
            int dest= queries[i][1];
            vector<bool> visited(numCourses,false);
            ans[i]= DFS(src,dest,visited,adj);
        }
      return ans;  
    }
};