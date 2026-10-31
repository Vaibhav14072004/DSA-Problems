// TC O(N*M)
// SC= O(N*M)

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        
        // {{row,col},time}
        queue<pair<pair<int,int>,int>> q;

        int cntFresh= 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]== 2)
                {
                    q.push({{i,j},0});
                }

                else if(grid[i][j]== 1)
                {
                    cntFresh++;
                }
            }
        }

        vector<int> rdir= {-1,0,1,0};
        vector<int> cdir= {0,1,0,-1};

        int maxtime= 0;
        int cnt= 0;
        while(!q.empty())
        {
            auto top= q.front();
            q.pop();
            int r= top.first.first;
            int c= top.first.second;
            int t= top.second;
            maxtime= max(maxtime,t);

            for(int k=0; k<4; k++)
            {
                int nrow= r+rdir[k];
                int ncol= c+cdir[k];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol]== 1)
                {
                    cnt++;
                    q.push({{nrow,ncol},t+1});
                    grid[nrow][ncol]= 2;
                }
            }
        }

       if(cnt != cntFresh) return -1;
       return maxtime;
    }
};