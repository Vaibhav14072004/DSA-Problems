class Solution {
public:
    int minimumArea(vector<vector<int>>& grid,int i1,int j1,int i2,int j2) {
        int n =grid.size();
        int m =grid[0].size();
        int left = m;
        int right = -1;
        int up = n ;
        int down = -1;
        for(int i =i1;i<=i2;i++){
            for(int j =j1;j<=j2;j++){
                if(grid[i][j]==1){
                    left=min(left,j);
                    right=max(right,j);
                    up=min(up,i);
                    down=max(down,i);
                }
            }
        }
        if(right==-1){
            return 0 ;
        }
        int x = right-left+1;
        int y =down-up+1;
        return x*y;
    }
    int minimumSum(vector<vector<int>>& grid) {
        int ans =30*30;
        int n =grid.size();
        int m= grid[0].size();
        for(int j =0;j<m;j++){
            int right = minimumArea(grid,0,j,n-1,m-1);
            for(int k = 0;k<j;k++){
                int cut1 = minimumArea(grid,0,k,n-1,j-1);
                int cut2 = minimumArea(grid,0,0,n-1,k-1);
                ans=min(ans,(cut1+cut2+right));
            }
            for(int i =0;i<n;i++){
                int cut1 = minimumArea(grid,i,0,n-1,j-1);
                int cut2 = minimumArea(grid,0,0,i-1,j-1);
                ans=min(ans,(cut1+cut2+right));               
            }

            int left = minimumArea(grid,0,0,n-1,j-1);
            for(int k = j;k<m;k++){
                int cut1 = minimumArea(grid,0,k,n-1,m-1);
                int cut2 = minimumArea(grid,0,j,n-1,k-1);
                ans=min(ans,(cut1+cut2+left));
            }
            for(int i =0;i<n;i++){
                int cut1 = minimumArea(grid,i,j,n-1,m-1);
                int cut2 = minimumArea(grid,0,j,i-1,m-1);
                ans=min(ans,(cut1+cut2+left));               
            }
        }

        for(int i =0;i<n;i++){
            int down = minimumArea(grid,i,0,n-1,m-1);
            for(int k = 0;k<m;k++){
                int cut1 = minimumArea(grid,0,k,i-1,m-1);
                int cut2 = minimumArea(grid,0,0,i-1,k-1);
                ans=min(ans,(cut1+cut2+down));
            }
            for(int j =0;j<i;j++){
                int cut1 = minimumArea(grid,j,0,i-1,m-1);
                int cut2 = minimumArea(grid,0,0,j-1,m-1);
                ans=min(ans,(cut1+cut2+down));               
            }

            int up = minimumArea(grid,0,0,i-1,m-1);
            for(int k = 0;k<m;k++){
                int cut1 = minimumArea(grid,i,k,n-1,m-1);
                int cut2 = minimumArea(grid,i,0,n-1,k-1);
                ans=min(ans,(cut1+cut2+up));
            }
            for(int j =i;j<n;j++){
                int cut1 = minimumArea(grid,j,0,n-1,m-1);
                int cut2 = minimumArea(grid,i,0,j-1,m-1);
                ans=min(ans,(cut1+cut2+up));               
           }
        }
       return ans;  
    }
};