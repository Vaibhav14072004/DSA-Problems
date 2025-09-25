class Solution {
public:
   
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size(),0));
        int r=triangle.size();
        for(int i=0;i<triangle[r-1].size();i++){
            dp[r-1][i]=triangle[r-1][i];
        }
        for(int i=r-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};