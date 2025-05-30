// Ques of Multi source BFS
// We have to start BFS from all the nodes which is water (ht= 0), and assign height of all its neighbour as 1

// TC= O(2* (M*N))
// SC= O(M*N)

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n= isWater.size();
        int m= isWater[0].size();

        vector<vector<int>> ans(n,vector<int>(m,-1));
        queue<pair<int,int>> q;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                // ht of water cell is 0, we have to start BFS from all that nodes
                if(isWater[i][j]== 1){
                    q.push({i,j});
                    ans[i][j]= 0;
                }
            }
        }

        vector<int> dirX= {-1,0,1,0};
        vector<int> dirY= {0,1,0,-1};

        while(!q.empty())
        {
            int row= q.front().first;
            int col= q.front().second;
            q.pop();

            for(int k=0; k<4; k++)
            {
               int newX= row + dirX[k];
               int newY= col+ dirY[k];

               if(newX >= 0 && newX < n && newY >= 0 && newY < m && ans[newX][newY]== -1)
               {
                   ans[newX][newY]= ans[row][col] + 1;
                   q.push({newX,newY});
               }
            }  
        }
    return ans;
    }
};