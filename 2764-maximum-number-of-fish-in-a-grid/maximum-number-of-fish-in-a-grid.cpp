// Approach 3 ->> Using DSU (Disjoint Set Union)
// TC of DSU is O(No of cells) ->> O(N*M)

// Overall TC= O[(N*M)* alpha(N*M)]

// To convert 2D array into 1D array -> (i* cols)+ j

class DSU {
public:
   vector<int> parent;
   vector<int> count;

   DSU(int n)
   {
      parent.resize(n);
      count.resize(n,0);
      for(int i=0; i<n; i++){
         parent[i]= i;
      }
   }

   int findParent(int node)
   {
      if(node== parent[node]){
         return node;
       }
      return parent[node]= findParent(parent[node]);
   }

   void Union(int u,int v)
   { 
      int parent_u= findParent(u);
      int parent_v= findParent(v);
      if(parent_u== parent_v){
         return;
      } 

      if(count[parent_u] > count[parent_v])
      {
          parent[parent_v]= parent_u;
          count[parent_u]+= count[parent_v];
      }
      else
      {
         parent[parent_u]= parent_v;
         count[parent_v]+= count[parent_u];
      }
   }
};


class Solution{
 public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n= grid.size();    // rows
        int m= grid[0].size(); // columns
    
        vector<int> dirX= {-1,0,1,0};
        vector<int> dirY= {0,1,0,-1};

        DSU dsu(n*m);

        // fill count array of DSU with value of grid[i][j]
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] > 0)
                {
                    // convert 2D array into 1D ->> (i* cols)+j
                    int idx= (i*m)+j;
                    dsu.count[idx]= grid[i][j];
                }
            }
        }
        

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] > 0)
                {
                    // convert 2D index into 1D index->> (i* cols)+j
                    int idx= (i*m)+j;
                    
                    // now check all 4 directions..
                    for(int k=0; k<4; k++)
                    {
                       int newX= i+dirX[k];
                       int newY= j+dirY[k];

                       if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] > 0)
                       {
                       // convert 2D index into 1D index ->> (i*cols)+j
                       int newIdx= (newX* m)+ newY;

                       int oldParent= dsu.findParent(idx);
                       int newParent= dsu.findParent(newIdx);

                       if(oldParent != newParent)
                       {
                          dsu.Union(oldParent,newParent);
                       } 
                     }
                  }
                } 
            }
        }
    
    // maximum count will be answer
    int ans= *max_element(dsu.count.begin(), dsu.count.end());
    return ans;
    }
};





// Approach 2 -> BFS
// TC= O(N*M)

/*

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;
        vector<int> dirX = {-1, 0, 1, 0};
        vector<int> dirY = {0, 1, 0, -1};

        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                if (grid[i][j] > 0)
                {
                    int sum = 0;
                    queue<pair<int, int>> pq;
                    pq.push({i, j});

                    while(!pq.empty())
                    {
                        int row = pq.front().first;
                        int col = pq.front().second;
                        sum+= grid[row][col];
                        grid[row][col] = 0;
                        pq.pop();

                        for (int k = 0; k < 4; k++) 
                        {
                            int newX = row + dirX[k];
                            int newY = col + dirY[k];
                            if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] > 0) {
                                pq.push({newX, newY});
                            }
                        }
                    }

                    maxi= max(maxi,sum);
                }
            }
        }
        return maxi;
    }
};

*/







// Approach 1 -> Using DFS
// TC= O(N*M)

/*

class Solution {
public:
    int DFS(int i, int j, vector<vector<int>> &grid, int n, int m)
    {
        if(i < 0 || i>= n || j< 0 || j>= m || grid[i][j]== 0){
            return 0;
        }

        int fish= grid[i][j];
        grid[i][j]= 0;

        vector<int> dirX= {-1,0,1,0};
        vector<int> dirY= {0,1,0,-1};

        for(int k=0; k<4; k++)
        {
            int newX= i+ dirX[k];
            int newY= j+ dirY[k];

            // check id newX, newY are valid..
            if(newX >= 0 && newX < n && newY >= 0 && newY < m &&
grid[newX][newY] > 0)
            {
                fish+= DFS(newX,newY,grid,n,m);
            }
        }
    return fish;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        int maxi= 0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] > 0)
                {
                    maxi= max(maxi, DFS(i,j,grid,n,m));
                }
            }
        }
       return maxi;
    }
};

*/