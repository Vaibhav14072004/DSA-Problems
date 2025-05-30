// Approach 1 -> Using DFS
// TC= O(N)

class Solution {
public:
    void DFS(int node,vector<bool> &visited,vector<int> &dist,vector<int> &edges)
    {
        if(visited[node]){
            return;
        }

        visited[node]= true;
        int neighbour= edges[node];

        if(neighbour != -1 && !visited[neighbour])
        {
            dist[neighbour]= 1+ dist[node];
            DFS(neighbour,visited,dist,edges);
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n= edges.size();

        // since every node can lead to only single node,no need create adjList
        vector<int> dist1(n,INT_MAX);
        vector<int> dist2(n,INT_MAX);

        vector<bool> visited(n,false);
        dist1[node1]= 0;

        DFS(node1,visited,dist1,edges);

        fill(visited.begin(),visited.end(),false);

        dist2[node2]= 0;
        DFS(node2,visited,dist2,edges);

        int node= -1;
        int minDist= INT_MAX;
        for(int i=0; i<n; i++)
        {
            int maxD= max(dist1[i],dist2[i]);
            if(minDist > maxD)
            {
                minDist= maxD;
                node= i;
            }
        }
      return node;  
    }
};