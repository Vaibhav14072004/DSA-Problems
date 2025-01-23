// Approach 1 -> 
// TC= O(2* (M*N))

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();

        vector<int> rowCnt(n,0);
        vector<int> colCnt(m,0);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]== 1)
                {
                    rowCnt[i]++;
                    colCnt[j]++;
                }
            }
        }
        
        int ans= 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]== 1 && (rowCnt[i] > 1 || colCnt[j] > 1))
                {
                    ans++;
                }
            }
        }
    return ans;
    }
};






/*  <---- WRONG APPROACH ----->
   It double counted the server in both rows and columns  

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        int ans= 0;

        // same row
        for(int i=0; i<n; i++)
        {
            int row= 0;
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]== 1)
                {
                    row++;
                }
            }
            if(row > 1)
            {
                ans+= row;
            }
        }

        // same col..
        for(int j=0; j<m; j++)
        {
            int col= 0;
            for(int i=0; i<n; i++)
            {
                if(grid[i][j]== 1)
                {
                   col++;
                }
            }

            if(col > 1)
            {
                ans+= col;
            }
        }

    return ans;
    }
};
*/
