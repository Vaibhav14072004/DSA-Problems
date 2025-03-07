// NOT Optimized
// Approach 3 -> Creating a matrix of n*n size of type bool whether every node to other is prerequisite or NOT

// TC= O[N^2* (V+E)]

class Solution{
public:
    bool DFS(int src, int dest, vector<vector<int>> &adj, vector<bool> &visited)
    {
        if(visited[src]){
            return false;
        }

        visited[src]= true;
        if(src== dest){
            return true;
        }

        for(auto it: adj[src])
        {
            if(!visited[it])
            {
                if(DFS(it,dest,adj,visited))
                {
                    return true;
                }
            }
        }
    return false;
    }


    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) 
    {
        // create adj list..
        vector<vector<int>> adj(numCourses);
        for(auto it: prerequisites)
        {
            adj[it[0]].push_back(it[1]);
        }

        vector<vector<bool>> matrix(numCourses, vector<bool> (numCourses,false));
        for(int i=0; i<numCourses; i++)
        {
            for(int j=0; j<numCourses; j++)
            {
                if(i== j) continue;
                vector<bool> visited(numCourses,false);
                matrix[i][j]= DFS(i,j,adj,visited);
            }
        }
        
        vector<bool> ans(queries.size(), false);
        for(int i=0; i<queries.size(); i++)
        {
            int src= queries[i][0];
            int dest= queries[i][1];
            ans[i]= matrix[src][dest];
        }
    return ans;
    }
};







// Approach 2 ->> Modified Topological Sort using BFS + Map
// (Queue , Indegree vector for topo sort and unordered_map for maintaing the transitive property)

// TC= O[V* (V+E)] bcoz we are iterating on map again to fill transitive dependency so we multiply V

/*

class Solution{
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) 
    {
         vector<int> indegree(numCourses,0);
         
         // first create adj list
         vector<vector<int>> adj(numCourses);
         for(auto it: prerequisites)
         {
             adj[it[0]].push_back(it[1]);
             indegree[it[1]]++;
         }
         
         queue<int> q;
         for(int i=0; i<numCourses; i++){
            if(indegree[i]== 0)
               q.push(i);
         }
         
         // map to store all the previous transitive prerequisites of curr node
         unordered_map<int,unordered_set<int>> mp;

         while(!q.empty())
         {
            int node= q.front();
            q.pop();
            
            for(auto it: adj[node])
            {
                // store all previous prequisites of prev node also (transitive dependency) 
                mp[it].insert(node);

                // Extra TC= O(V) will be multiplied bcoz of
                for(auto j: mp[node])
                { 
                    mp[it].insert(j);  
                }

                indegree[it]--;
                if(indegree[it]== 0)
                {
                    q.push(it);
                }
            }
         }
            
         vector<bool> ans(queries.size(),false);
         for(int i=0; i<queries.size(); i++)
         {
             int src= queries[i][0];
             int dest= queries[i][1];

             // we have to check whether prerequisite of dest is src or NOT (src -> dest)
             if(mp[dest].count(src))
             {
                ans[i]= true;
             }
         }
    return ans;
    }
};

*/







// Approach 1.2 -> Create Adj list and using BFS 
// find whether path form src to dest exists or NOT

// TC= O[q* (V+E)]

/*

class Solution{
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int q= queries.size();

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
            queue<int> q;
            q.push(src);

            while(!q.empty())
            {
                int node= q.front();
                q.pop();
                visited[node]= true;

                if(node== dest)
                {
                   ans[i]= true;
                   break;
                }

                for(auto it: adj[node])
                {
                    if(!visited[it])
                    {
                        q.push(it);
                    }
                }
            }
        }
    return ans;
    }
};

*/






// Approach 1.1 ->> Create adj list and using DFS find whether path from src to dest exists or NOT
// TC= O[q* (V+E)] + O(E)
// SC= O(V+E)

/*

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

*/