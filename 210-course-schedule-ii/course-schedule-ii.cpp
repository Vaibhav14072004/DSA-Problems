// Approach 2 -> Topological Sort using DFS (First detect whether cycle exists or NOT)
// Using stack and visited vector, pathVisited vector for cycle detection

// TC= O(V+E)

class Solution{
 public:
    bool DFS(int node, vector<bool> &visited,vector<bool> &pathVisited,stack<int> &st, vector<vector<int>> &adj)
    {
        visited[node]= true;
        pathVisited[node]= true;

        for(auto it: adj[node])
        {
            if(!visited[it])
            {
                if(DFS(it,visited,pathVisited,st,adj)== true)
                {
                    return true;
                }
            }
                        
            // if visited[i] && pathVisited[i]== true;
            else if(pathVisited[it])
            {
               return true;
            }
        }

        pathVisited[node]= false;
        st.push(node);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        for(auto it: prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }

        stack<int> st;
        vector<int> topo;
        vector<bool> visited(numCourses,false);
        vector<bool> pathVisited(numCourses,false);

        for(int i=0; i<numCourses; i++)
        {
            if(!visited[i])
            {
                // if cycle exists, return empty vector
                if(DFS(i,visited,pathVisited,st,adj)== true)
                {
                    return {};
                }
            }
        }
        
        // if there would be cycle, topological sort is NOT valid
        if(st.size() != numCourses)
        {
            return {};
        }
        
        while(!st.empty())
        {
            topo.push_back(st.top());
            st.pop();
        }

    return topo;
    }
};





// Approach 1 ->> Using Topological sort (BFS)
// Using Queue and Indegree vector
// TC= O(V+E)

/*

class Solution{
public:
   vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
       
         // (a,b) =>> bi -> ai
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        queue<int> q;
        vector<int> topo;
        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i]== 0){
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int node= q.front();
            topo.push_back(node);
            q.pop();
            
            for(auto it: adj[node])
            {
                indegree[it]--;
                if(indegree[it]== 0)
                {
                    q.push(it);
                }
            }
        }
    
    if(topo.size() != numCourses)
         return {};

    return topo;
    }
};

*/