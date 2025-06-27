// Approach 1 ->> Using DFS
// TC= O(V+E)

class Solution {
public:
    int DFS(int curr,int parent,unordered_map<int,vector<int>> &adj,vector<bool> &hasApple)
    {
        int time= 0;
        for(auto it: adj[curr])
        {
            if(it== parent){
                continue;
            }

            int childTime= DFS(it,curr,adj,hasApple);

            if(childTime > 0 || hasApple[it]){
                time+= childTime+2;
            }
        }
      return time;  
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>> adj;

        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        return DFS(0,-1,adj,hasApple);
    }
};