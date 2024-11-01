// Approach 1 -> Top Down(Recursion + Memoization)
// TC= O(N*2*N) ->> O(N^2)

class Solution{
public:
    int solve(int i, bool aliceTurn, int M, vector<int> &piles, vector<vector<vector<int>>> &dp)
    {
        int n= piles.size();
        if(i >= n)
        {
            return 0;
        }

        if(dp[i][aliceTurn][M] != -1)
        {
            return dp[i][aliceTurn][M];
        }
        
        int ans;
        
        // In Alice turn, we have to make max but in bob turn, we expect min for alice
        if(aliceTurn){
           ans= INT_MIN;
        }
        else{
          ans= INT_MAX;
        }
        
        int stones= 0;
        for(int x= 1; x<= min(2*M, n-i); x++)
        {    
           stones+= piles[i+x-1];
           
           if(aliceTurn)
           {
              ans= max(ans, stones+ solve(i+x, !aliceTurn, max(M,x), piles, dp));
           }
           else
           {
              ans= min(ans, solve(i+x, !aliceTurn, max(M,x), piles, dp));
           }  
        }
    return dp[i][aliceTurn][M]= ans;
    }


    int stoneGameII(vector<int>& piles) {
        int n= piles.size();
        int M= 1;
        bool aliceTurn= true;   
 
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (n+1, -1)));
        return solve(0,aliceTurn,M,piles, dp);
    }
};








/*  RECURSIVE APPROACH
    TC= O[N* 2^(N)]  ->> bcoz we have 2 choices either pick by alice or bob

class Solution {
public:
    int solve(int i,bool aliceTurn,int M, vector<int> &piles)
    {
        int n= piles.size();
        if(i >= n)
        {
            return 0;
        }
        
        // we play optimally ->> in case of alice turn, we expect max but in bob turn, we expect min for alice
        int result= (aliceTurn== true) ? INT_MIN : INT_MAX;

        int stones= 0;
        for(int x=1; x<= min(2*M, n-i); x++)
        {
            stones+= piles[i+x-1];

            if(aliceTurn)
            {
                result= max(result, stones + solve(i+x, !aliceTurn, max(M,x), piles));
            }
            else
            {
                result= min(result, solve(i+x, !aliceTurn, max(M,x),piles));
            }
        }
    return result;   
    }

    int stoneGameII(vector<int>& piles) {
        int n= piles.size();
        int M= 1;
        bool aliceTurn= true;

        return solve(0,aliceTurn,M,piles);
    }
};

*/