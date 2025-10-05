class Solution {
    void bfs(vector<vector<int>>&heights,vector<vector<int>>&vis,queue<pair<int,int>>&q)
    {  int n=heights.size();
       int m=heights[0].size();
        
        int drow[]={1,0,-1,0};
        int dcol[]={0,1,0,-1};

        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int dr=drow[i]+r;
                int dc=dcol[i]+c;
                if(dr>=0 && dc>=0 && dr<n && dc<m && !vis[dr][dc] && heights[dr][dc]>=heights[r][c])
                {
                    vis[dr][dc]=1;
                    q.push({dr,dc});
                }
            }
        }
    }
public:

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>ans;
        queue<pair<int,int>>pq;
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>visP(n,vector<int>(m,0));
        for(int i=0;i<heights.size();i++)
        {
            pq.push({i,0});
            visP[i][0]=1;
        }
        for(int i=0;i<heights[0].size();i++)
        {
               pq.push({0,i});
               visP[0][i]=1;
        }
    
        queue<pair<int,int>>aq;
        vector<vector<int>>visA(n,vector<int>(m,0));
        for(int i=0;i<heights.size();i++)
        {
            aq.push({i,heights[0].size()-1});
            visA[i][m-1]=1;
        }
        for(int i=0;i<heights[0].size();i++)
        {
            aq.push({heights.size()-1,i});
            visA[n-1][i]=1;
        }
        //now call bfs twice one for atlantic and for pacific
         bfs(heights,visP,pq);
         bfs(heights,visA,aq);
     
         for(int i=0;i<n;i++)
         {
            for(int j=0;j<m;j++)
            {
                if(visA[i][j] && visP[i][j])
                {
                    ans.push_back({i,j});
                }
            }
         }
         return ans;

    }
};