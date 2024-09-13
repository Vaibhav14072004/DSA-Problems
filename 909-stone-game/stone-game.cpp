class Solution {
public:
    int solve(int left, int right, int turn, vector<int> &piles, vector<vector<int>> &dp)
    {
        // base case
        if(left > right){
            return 0;
        }

        if(left== right){
            return piles[left];
        }
        
        if(dp[left][right] != -1){
            return dp[left][right];
        }
    
    // wIn Alex turn, alex wants to maximize the score for Alex...
        if(turn)
        {
            dp[left][right]= max(piles[left] + solve(left+1,right, !turn, piles, dp), 
                 piles[right] + solve(left, right-1,!turn,piles,dp));
        }
    
    // else Bob turn, he wants to minimize the score for alex by excluding first or last pile...
        else
        {
            dp[left][right]= min(-piles[left] + solve(left+1,right,!turn,piles,dp),
             -piles[right] + solve(left,right-1,! turn, piles,dp));
        }
    return dp[left][right];
    }


    bool stoneGame(vector<int>& piles) {
        int n= piles.size();

        vector<vector<int>> dp(n,vector<int> (n, -1));
        return solve(0,n-1,1,piles,dp) > 0;
    }
};