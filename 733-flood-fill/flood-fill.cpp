// Approach 1.1 -> Using DFS 
// No need to take visited vector, bcoz we have already changed its color

// TC=O(N*M)
// SC= O(M*N) for recursion stack space

class Solution {
public:
    void DFS(int i,int j,int &oldColor,int &color,vector<vector<int>> &image, vector<int> &rowDir, vector<int> &colDir)
    {
        int n= image.size();
        int m= image[0].size();

        for(int k=0; k<4; k++)
        {
            int nRow= i+ rowDir[k];
            int nCol= j+ colDir[k];

            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && image[nRow][nCol]== oldColor)
            {
                image[nRow][nCol]= color;
                DFS(nRow,nCol,oldColor,color,image,rowDir,colDir);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n= image.size();
        int m= image[0].size();
        
        int oldColor= image[sr][sc];
        image[sr][sc]= color;
        
        // base case for stopping -> infinite recursion...
        if(oldColor== color) return image;

        vector<int> rowDir= {-1,0,1,0};
        vector<int> colDir= {0,1,0,-1};

        DFS(sr,sc,oldColor,color,image,rowDir,colDir);
        return image;
    }
};







// Approach 2 -> Using BFS
// TC= O(N*M)
  
/*

class Solution{
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         int n= image.size();
         int m= image[0].size();

         vector<vector<bool>> visited(n,vector<bool> (m,false));
         int oldColor= image[sr][sc];
         
         image[sr][sc]= color;
         visited[sr][sc]= true;

         queue<pair<int,int>> q;
         q.push({sr,sc});

         vector<int> rowDir= {-1,0,1,0};
         vector<int> colDir= {0,1,0,-1};

         while(!q.empty())
         {
            int row= q.front().first;
            int col= q.front().second;
            q.pop();

            visited[row][col]= true;
            image[row][col]= color;

            for(int k=0; k<4; k++)
            {
                int newRow= row+ rowDir[k];
                int newCol= col+ colDir[k];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                 !visited[newRow][newCol] && image[newRow][newCol]== oldColor)
                {
                    q.push({newRow,newCol});
                }
            }
         }
     return image;  
    }
};

*/





// Approach 1 -> Using DFS
// TC=O(N*M)
// SC= O(M*N) for recursion stack space

/*

class Solution {
public:
    void DFS(int i,int j,int &oldColor,int &color,vector<vector<int>> &image,vector<vector<bool>> &visited)
    {
        visited[i][j]= true;
        
        int n= image.size();
        int m= image[0].size();
        vector<int> rowDir= {-1,0,1,0};
        vector<int> colDir= {0,1,0,-1};

        for(int k=0; k<4; k++)
        {
            int nRow= i+ rowDir[k];
            int nCol= j+ colDir[k];

            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !visited[nRow][nCol] && image[nRow][nCol]== oldColor)
            {
                image[nRow][nCol]= color;
                DFS(nRow,nCol,oldColor,color,image,visited);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n= image.size();
        int m= image[0].size();

        vector<vector<bool>> visited(n,vector<bool> (m,false));
        
        int oldColor= image[sr][sc];
        image[sr][sc]= color;

        DFS(sr,sc,oldColor,color,image,visited);
        return image;
    }
};

*/