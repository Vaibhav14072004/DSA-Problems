// ...........  Using BFS ...........

/*     INTUTION =>>

Terminal nodes => Nodes that have outdegree= 0  ... Topo sort m hum indegree= 0 krte h
What if we change all edge directions and then apply topo sort

1) Reverse all the edge directions (i-> it) ko change kro (it->i)
2) Apply Topological sort and return the topologically sorted array...

Topological sort =>> 
a) Push all nodes with indegree= 0 in queue
b) Take out the first node from queue.. store it in ans ,,,, and for all its adjacent nodes reduce INDEGREE by 1
c) If adjacent node ki indegree= 0 ho jaaye to again push it into queue
d) if queue becomes empty return ans..

*/



class Solution{
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int V= graph.size();

      // ......... First CHANGE DIRECTION of all the EDGES .........
    //  (i -> it) ko change kro (it -> i)

     vector<int> reverseAdj[V];

     vector<int> indegree(V,0);
     // int indegree[V]= {0};

    
    for(int i=0; i<V; i++){
        for(auto it: graph[i]){
    
    reverseAdj[it].push_back(i);
    indegree[i]++;
        }
    }

      // Now apply logic of Topological sort => Push all nodes with indegree= 0 in queue
       vector<int> topo;
        queue<int> q;

    for(int i=0; i<V; i++){
      if(indegree[i]== 0){
          q.push(i);
      }
    }

    while(!q.empty()){
        int frontNode= q.front();
        topo.push_back(frontNode);
        q.pop();
    
    // reduce indegree of adjacent nodes by 1
        for(auto neighbour: reverseAdj[frontNode]){

            indegree[neighbour]--;
            
            if(indegree[neighbour]== 0){
                q.push(neighbour);
            }
        }
    }

// sort in ascending order .. topologically sorted array
sort(topo.begin(), topo.end());
return topo;
    }
};






//  ...........   Using DFS.......

// Approach 2 =>> Directly using adjacency matrix...
//                 just store ihe DFS call in some random variable....

/* 
1)  Any node which is part of a cycle is not a safe node
2)  Any node which leads to a cycle is also not a safe node
all the remaining nodes are safe nodes
*/

/*

class Solution {
private:
    bool checkSafeNodes(int node, vector<vector<int>>& graph, vector <int> &visited,
    vector <int> &pathVisited){
        visited[node] = 1;
        pathVisited[node] = 1;

        for(auto neighbour : graph[node]){
            if(!visited[neighbour]){
                if(checkSafeNodes(neighbour, graph, visited, pathVisited) == true){
                    return true;
                }
            }
            else if(pathVisited[neighbour]){
                return true;
            }
        }

        pathVisited[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector <int> safeNodes;
        vector <int> visited(n, 0);
        vector <int> pathVisited(n, 0);

        for(int i = 0; i<n; i++){
            if(!visited[i]){

                // without calling dfs call directly store it in some variable
                int cycleFound = checkSafeNodes(i, graph, visited, pathVisited);
            }
        }

        for(int i = 0; i<n; i++){
            if(pathVisited[i] == 0){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};

*/



/*
 ..............    VERY VERY IMPORTANT POINT............    
 
  If Adjacency Matrix is given (vector<vector<int>> graph).... first CONVERT it 
  into Adjacency List (vector<int> adj[])

Adj Matrix =>> convert kro =>> Adj List

Using this code.....

    vector<int> adj[V];
    for (int i = 0; i < V; i++) {
    for (int j : graph[i]) {
        adj[i].push_back(j);
    }}
  */


/*
Terminal Node =>> Node having (Outdegree= 0) =>> 'No outgoing edges' from that node

Safe Node =>> Every possible path starting from that node leads to a terminal node.

OBSERVATIONS to NOTE->> Safe node CANNOT be =->>
1) Any node which is a part of CYCLE CANNOT be a safe node
2) Every node that is connected to a CYCLE ... CANNOT be a safe node

*/

// Using DFS

/*

class Solution {
private:
    bool DFS(int node, vector<int> adj[], vector<int> &visited, vector<int> &pathVisited) {
        visited[node] = 1;
        pathVisited[node] = 1;

        for (auto it : adj[node]) {
            if (!visited[it]) {
                if (DFS(it, adj, visited, pathVisited)) {
                    return true;
                }
            }
            // if it is already visited and is on the same path =>> cycle Present..
            else if (pathVisited[it] == 1) {
                return true;
            }
        }

        // If cycle NOT Found...before going back the recursive call, mark pathVisited of that node to 0 again..
        pathVisited[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

      // Check for an empty graph
    if (V == 0) {
        return {};
    }

        // Convert adjacency matrix to adjacency list

        vector<int> adj[V];
        for (int i = 0; i < V; i++) {
    for (int j : graph[i]) {
        adj[i].push_back(j);
    }
}

        vector<int> visited(V, 0);
        vector<int> pathVisited(V, 0);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
               int temp=  DFS(i, adj, visited, pathVisited);
            }
        }

        vector<int> safe;

// If cycle is found =>> pathVisited[node] will still remain 1... even after the return of DFS call
// But if Cycle NOT Found =>> pathVisited[node] = 0 after the return of DFS call

    // Safe nodes are nodes that are NOT a part of a cycle and are NOT connected to a cycle...
        for (int i = 0; i < V; i++) {
            if (pathVisited[i] == 0) {
                safe.push_back(i);
            }
        }

        return safe;
    }
};

*/



