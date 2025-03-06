// Approach 1 ->> Using Topological sort (BFS)
// Using Queue and Indegree vector

// TC= O(V+E)

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

