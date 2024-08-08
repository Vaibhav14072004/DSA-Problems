class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        int steps=0,i=0,vis=1;
        vector<vector<int>> ans;
        ans.push_back({rStart,cStart});
        while(vis<rows*cols){
            if(i%2==0)
            {
              ++steps;
            }
            for(int j=0; j<steps; ++j){
                rStart += dx[i];
                cStart += dy[i];
                if(rStart>=0 and cStart>=0 and rStart<rows and cStart<cols){
                    ++vis;
                    ans.push_back({rStart,cStart});
                }
            }
            i = (i+1)%4;
        }
        return ans;
    }
};