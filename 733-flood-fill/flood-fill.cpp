// Approach 1 -> Using DFS
// TC=O(N*M)

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