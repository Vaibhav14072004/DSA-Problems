// TC= O(N)

class Solution {
public:
    int dfs(int node, int parent,vector<vector<int>> &adjList,vector<int> &values, int &k, long long &sum)
    {
         sum+= values[node];
         int cnt= 0;

         for(int neighbour: adjList[node])
         {
            if(neighbour != parent)
            {
                long long childSum= 0;
               cnt+= dfs(neighbour, node, adjList, values, k, childSum);

               sum+= childSum;
            }  
         }

         if(sum % k== 0)
         {
            cnt++;
            sum= 0;
         }

         return cnt;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        // create adjList
        vector<vector<int>> adjList(n);
        for(auto it: edges)
        {
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        
        long long sum= 0;
        return dfs(0,-1,adjList,values,k,sum);
    }
};