// Approach 1 -> Using DFS 
// TC= O(N*M)

class Solution {
public:
   bool dfs(int i, int j, vector<vector<int>> &visited, vector<vector<int>> &grid1, vector<vector<int>> &grid2)
   {
       int n= grid1.size();    // row
       int m= grid1[0].size(); // col

       visited[i][j]= 1;
      
      // do not perform dfs if grid1[i][j] != 1

      bool isIsland= true;

       if(grid1[i][j]== 0)
       {
          isIsland= false;
       }
       
       // check for all 4 directions, up,down,left,right
       int row[4]= {-1,0,1,0};
       int col[4]= {0,1,0,-1};
       
       for(int k= 0; k<4; k++)
       {
          int newRow= i+ row[k];
          int newCol= j+ col[k];
          
        if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && !visited[newRow][newCol] && grid2[newRow][newCol]== 1)
          {
              if(!dfs(newRow, newCol,visited,grid1,grid2))
              {
                isIsland= false;
              }
          }
       }
      return isIsland; 
   }


    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2)
    {
        int n= grid1.size(); // rows
        int m= grid1[0].size(); // columns

        vector<vector<int>> visited(n, vector<int> (m, 0));
        
        int cnt= 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!visited[i][j] && grid2[i][j]== 1)
                {
                    if(dfs(i,j,visited,grid1,grid2))
                       cnt++;
                }
            }
        }
       return cnt; 
    }
};






/*

class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans = 0;
        int n = grid1.size(), m = grid1[0].size();

        vector<vector<bool>> vis(n, vector<bool> (m, false));
        queue<pair<int, int>> q;
        int row[] = {0,0,1,-1};
        int col[] = {-1,1,0,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j] == 1 && !vis[i][j]){
                    vis[i][j] = true;
                    bool flag = true;
                    if(grid1[i][j] != 1) flag = false;
                    q.push({i, j});
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        vis[x][y] = true;
                        for(int k=0;k<4;k++){
                            int a = x + row[k];
                            int b = y + col[k];
                            if(a >= 0 && a < n && b >= 0 && b < m){
                                if(grid2[a][b] == 1 && !vis[a][b]){
                                    vis[a][b] = true;
                                    q.push({a, b});
                                    if(grid1[a][b] != 1) flag = false;
                                }
                            }
                        }
                    }
                    if(flag) ans++;
                }
            }
        }
        return ans;

    }
};

*/