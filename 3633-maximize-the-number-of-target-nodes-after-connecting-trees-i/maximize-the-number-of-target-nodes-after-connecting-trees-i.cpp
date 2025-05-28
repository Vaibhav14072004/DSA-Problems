// Approach 2 -> Using DFS -> Using parent instead of using visited vector
// TC= O(N* (N+M))

class Solution{
public:
    int DFS(int node, unordered_map<int,vector<int>> &adj, int d, int n, int parent)
    {
        if(d < 0){
            return 0;
        }

        int cnt= 1; // to cnt the no of nodes < d
        for(int &neighbour: adj[node])
        {
             // if(!visited[neighbour])
             if(neighbour != parent)
             {
                cnt+= DFS(neighbour,adj,d-1,n,node);
             }
        }
      return cnt;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k)
    {
        int n= edges1.size()+1;
        int m= edges2.size()+1;

        // first create adj list for tree1
        unordered_map<int,vector<int>> adj1;
        for(auto &it: edges1)
        {
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }

        // create adj list for tree2
        unordered_map<int,vector<int>> adj2;
        for(auto &it: edges2)
        {
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }

        vector<int> tree1(n);
        vector<int> tree2(m);

    // we have to connect all nodes of tree1 with that node of tree2 that gives max cnt of nodes, so dist is reduced by 1
        for(int i=0; i<m; i++)
        {
            tree2[i]= DFS(i,adj2,k-1,m,-1);
        }

        int maxiTree2= *max_element(tree2.begin(),tree2.end());
        for(int i=0; i<n; i++)
        {
            tree1[i]= DFS(i,adj1,k,n,-1);
            tree1[i]+= maxiTree2;    
        }

        return tree1;
    }
};





// Approach 1 -> Using BFS
// TC= O(N* (N+M))

/*

class Solution {
public:
    int BFS(int node, unordered_map<int,vector<int>> &adj, int d, int n)
    {
        // {node,dist}
        queue<pair<int,int>> q;
        q.push({node,0});

        vector<bool> visited(n,false);
        visited[node]= true;
        
        // to count all nodes which are within the dist of d
        int cnt= 0;
        while(!q.empty())
        {
            int curr= q.front().first;
            int dist= q.front().second;
            q.pop();

            // skip the iteration, if this node is at dist > d
            if(dist > d)
            {
                continue;
            }

            // cnt++ bcoz this node lies within dist < d
            cnt++;

            // check for its neighbours...
            for(int &neighbour: adj[curr])
            {
                if(!visited[neighbour])
                {
                    visited[neighbour]= true;
                    q.push({neighbour,dist+1});
                }
            }
        }
    return cnt;
    }


    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k)
    {
        // since there are n+1 nodes..
        int n= edges1.size()+1;
        int m= edges2.size()+1;

        vector<int> tree1(n);
        vector<int> tree2(m);

        // create adjList for tree1
        unordered_map<int,vector<int>> adj1;
        for(int i=0; i<edges1.size(); i++)
        {
            adj1[edges1[i][0]].push_back(edges1[i][1]);
            adj1[edges1[i][1]].push_back(edges1[i][0]);
        }

        // create adjList for tree2
        unordered_map<int,vector<int>> adj2;
        for(int i=0; i<edges2.size(); i++)
        {
            adj2[edges2[i][0]].push_back(edges2[i][1]);
            adj2[edges2[i][1]].push_back(edges2[i][0]);
        }

        for(int i=0; i<n; i++)
        {
           tree1[i]= BFS(i,adj1,k,n); 
        }

        for(int i=0; i<m; i++)
        {
            // the dist will be k-1 as 1 dist is needed to connect tree1 with tree2
            tree2[i]= BFS(i,adj2,k-1,m);
        }

        // we need to connect every node of tree1 with that node of tree2 always that would guarantee
        // maximum connected nodes... so find maximum out of tree2 and add it in every entry of tree1 vector..
        int maxiTree2= *max_element(tree2.begin(),tree2.end());

        for(int i=0; i<n; i++)
        {
            tree1[i]+= maxiTree2;
        }
      return tree1;  
    }
};

*/