// TC= O[q* (V+E)]

class Solution {
public:
    int BFS(int n, unordered_map<int, vector<int>>& adj) 
    {
        vector<int> visited(n,0);
        int level= 0;
        queue<int> q;
        q.push(0);
        visited[0]= 1;

        while(!q.empty())
        {
            int len= q.size();
            while(len--)
            {
                int front= q.front();
                q.pop();

                if(front== n-1)
                {
                    return level;
                }

                for(auto neighbour: adj[front])
                {
                    if(!visited[neighbour])
                    {
                        visited[neighbour]= 1;
                        q.push(neighbour);
                    }
                }
            }
            level++;
        }
     return -1;
    }


    vector<int> shortestDistanceAfterQueries(int n,vector<vector<int>>& queries) {
        vector<int> ans;
        unordered_map<int, vector<int>> adj;

        for (int i = 1; i < n; i++) {
            adj[i - 1].push_back(i);
        }

        for (auto it : queries) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);

            int shortestDist = BFS(n, adj);
            ans.push_back(shortestDist);
        }
        return ans;
    }
};