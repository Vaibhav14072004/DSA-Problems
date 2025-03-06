// Approach 1.1  ->DFS (Using separate visited and pathVisited vector)
// Detect cycle in directed graph

// TC= O(V+E)

class Solution {
public:
// to detect cycle in directed graph
    bool DFS(int node,vector<bool> &visited, vector<bool> &pathVisited, vector<vector<int>> &adj)
    {
        visited[node]= true;
        pathVisited[node]= true;

        for(auto it: adj[node])
        {
            if(!visited[it])
            {
                if(DFS(it,visited,pathVisited,adj))
                {
                    return true;
                }
            }

            // if visited[i] && pathVisited[i]== true, There will a cycle..
            else if(pathVisited[it])
            {
                return true;
            }
        }
        
        pathVisited[node]= false;
        return false;
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> adj(numCourses);
         
        // [ai, bi] means  ai <- bi ... bi comes before ai..
        for(auto it: prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> visited(numCourses,false);
        vector<bool> pathVisited(numCourses,false);
        
        // if cycle exists return false
        for(int i=0;i<numCourses; i++)
        {
            if(!visited[i])
            {
                if(DFS(i,visited,pathVisited,adj))
                {
                    return false;
                }
            }
        }
    return true;
    }
};