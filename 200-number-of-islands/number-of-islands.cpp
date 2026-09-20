// BFS
// TC= O(N^2)

class Solution {
public:
    void BFS(int i, int j,vector<vector<bool>> &visited,vector<vector<char>> &grid,int n,int m)
    { 
        visited[i][j]= true;
         queue<pair<int,int>> q;
         q.push({i,j});

         vector<int> rowDir= {-1,0,1,0};
         vector<int> colDir= {0,1,0,-1};

         while(!q.empty())
         {
            int r= q.front().first;
            int c= q.front().second;
            q.pop();

            for(int k=0; k<4; k++)
            {
                int nrow= r+ rowDir[k];
                int ncol= c+ colDir[k];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol]== '1')
                {
                    visited[nrow][ncol]= true;
                    q.push({nrow,ncol});
                }
            }
         }
    }

    int numIslands(vector<vector<char>>& grid) {
         int n= grid.size();
         int m= grid[0].size();
         int ans= 0;
         vector<vector<bool>> visited(n,vector<bool> (m,false));

         for(int i= 0; i<n; i++)
         {
            for(int j=0; j<m; j++)
            {
                if(!visited[i][j] && grid[i][j]== '1')
                {
                    ans++;
                    BFS(i,j,visited,grid,n,m);
                }
            }
         }
         return ans;
    }
};