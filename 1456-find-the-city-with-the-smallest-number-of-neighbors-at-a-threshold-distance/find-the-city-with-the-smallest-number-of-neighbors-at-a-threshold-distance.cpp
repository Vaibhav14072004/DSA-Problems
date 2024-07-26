/*   # 2 Approaches for this Question-:

   1) Apply Dijkstra Algorithm for all vertices... extra loop than the normal dijkstra=> TC= V* (E log V)
      calculate shortest dist from all nodes to all other nodes.....
      
      Diff than simple dijkstra bcoz it only find shorest dist from only one src node... 
      but here we have to find shortest dist from all nodes to all other nodes
      
      ----- Either use priority_queue-----
      ------ OR use set --------
     
   2) Apply Bellman Ford Algorithm => TC= O(n^3)

   3) Use DP
*/



// Approach 2 =>> Using Bellman Ford Algorithm
// TC => O( n^3)


class Solution{
public:

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

       vector<vector<int>> dist(n, vector<int> (n, INT_MAX));

            for(auto it: edges){
            dist[it[0]][it[1]]= it[2];
            dist[it[1]][it[0]]= it[2];
        }

    // dist from node to node itself will be 0 always
    for(int i=0; i<n; i++){
        dist[i][i]= 0;
    }


    // Now implement Floys Warshall algorithm using viva node (k)

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
        
        // skip that iteration where these dist are NOT Defined
        if(dist[i][k] == INT_MAX || dist[k][j]== INT_MAX){
            continue;
        }

            dist[i][j]= min(dist[i][j], dist[i][k]+ dist[k][j]);
            }
        }
    }
    
    int minCityCount= INT_MAX;
    int cityNo= -1;

    for(int i=0; i<n; i++){
          int count= 0;

        for(int j=0; j<n; j++){

        if(dist[i][j] <= distanceThreshold){
            count++;
            }
        }

        if(count<= minCityCount){
            minCityCount= count;
            cityNo= i;
        }
    }  // for loop of k ends here

return cityNo;
}
};






// Approach 1B => Using Dijkstra Algorithm ( Using set)...
// TC=    V* (E log V)
//  Beats 81.01 % users in C++ =>> 54 ms

/*

class Solution{
public:
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

     vector<pair<int,int>> adj[n];
    
    for(auto it: edges){
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

     set<pair<int, int>> st;

     int minCityCount= INT_MAX;
     int cityNo= -1;

     for(int i=0; i<n; i++){

         vector<int> dist(n, INT_MAX);
         dist[i]= 0;

         // { dist, node }
         st.insert({0,i});

         while(!st.empty()){

             // in set, we access first element by iterator...
             auto top= *(st.begin()); 
             int distance= top.first;
             int frontNode= top.second;
             st.erase(top);

             for(auto it: adj[frontNode]){
                 int neighbour= it.first;
                 int wt= it.second;

                 if(distance+ wt< dist[neighbour]){

// erase extra iterations... if dist is already updated by other node.. and now we have got same node with some less dist than the prev stored dist.... erase that pair which is stored with greater dist
                if(dist[neighbour] != INT_MAX){
                    st.erase({dist[neighbour], neighbour});
                }
                
                dist[neighbour]= distance+ wt;
                st.insert({dist[neighbour], neighbour});
                 }
             }
         }

        int count= 0;
         for(int k=0; k<n; k++){
             if(dist[k] <= distanceThreshold){
                 count++;
             }
         }

         if(count<= minCityCount){
             minCityCount= count;
             cityNo= i;
         }
     }   // for loop ends here...

     return cityNo;
}
};

*/





// Approach 1A => Using Dijkstra Algorithm ( Using priority_queue)...
// Beats 83.06 % users in C++ =>> 49 ms
// TC = V* (E log V)

/*

class Solution{
public:

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>> adj[n];

        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        int cityNo,minCityCount=1e9;
        
        // apply dijkstra Algorithm for all nodes => to find shortest dist of all nodes from all nodes
        for(int i=0;i<n;i++)
        {
            vector<int> dist(n,1e9);
            pq.push({0,i});

// dist[0]= 0 NI KRENGE.... bcoz here we have to find shortest dist from all nodes to all other nodes
// so each node will once become a src node

            dist[i]=0;
            while(!pq.empty())
            {
                // auto it= pq.top();
                int distance=pq.top().first;
                int frontNode=pq.top().second;
                pq.pop();

                for(auto it:adj[frontNode])
                {
                    int neighbour=it.first;
                    int wt=it.second;
                    if(distance + wt < dist[neighbour])
                    {
                        dist[neighbour] = distance + wt;
                        pq.push({dist[neighbour], neighbour});
                    }
                }
            }

            int count=0;
            for(int j=0;j<n;j++)
            {
                if(dist[j]<=distanceThreshold){
                      count++;
                }  
            }

        // we have to find min of all city counts
            if(count<= minCityCount)
            {
                minCityCount=count;
                cityNo = i;
            }
        }
        return cityNo;
    }
};

*/
