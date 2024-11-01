/*
   Top Down ->> 
   1. Index goes from 0 to n-1
   2. aliceTurn goes from 1 to 0 (1 means it is turn of Alice)
   3. M goes from 1 to n

   Bottom Up ->> Reverse order than Top Down
   1. Index goes from n-1 to 0
   2. aliceTurn goes from 0 to 1 (started from 0, bob)
   3. M goes from 1 to n (It cannot be reversed...)
        
*/

// Approach 2 -> Bottom Up(Tabulation)

// TC= O(N^3)  -> more than memoization code of N^2


class Solution{
public:
    int stoneGameII(vector<int>& piles) {
        int n= piles.size();
        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int> (n+1,0)));

        // populate suffix array to get sum of piles,bcoz index goes from backwards in tabulation..

        vector<int> suffix(n+1,0);
        for(int i=n-1; i>=0; i--)
        {
            suffix[i]= piles[i]+ suffix[i+1];
        }
        

        for(int i=n-1; i>=0; i--)
        {
            for(int aliceTurn= 0; aliceTurn<= 1; aliceTurn++)
            {
                for(int M= 1; M<= n; M++)
                {
                    // in case of Alice, we have to take max, in case of bob, we expect min for alice
                     if(aliceTurn== 1){
                        dp[i][aliceTurn][M]= INT_MIN;
                     }
                     else{
                        dp[i][aliceTurn][M]= INT_MAX;
                     }

                     for(int x= 1; x<= min(2* M, n-i); x++)
                     {
                         int stones= suffix[i]- suffix[i+x];
                        
                        // alice turn...
                         if(aliceTurn== 1)
                         {
                            dp[i][aliceTurn][M]= max(dp[i][aliceTurn][M], stones + dp[i+x][0][max(M,x)]);
                         }

                         // bob turn..
                         else
                         {
                            dp[i][aliceTurn][M]= min(dp[i][aliceTurn][M], dp[i+x][1][max(M,x)]);
                         }
                     }
                }
            }
        }

        return dp[0][1][1];
    }
};










// Approach 1 -> Top Down(Recursion + Memoization)
// TC= O(N*2*N) ->> O(N^2)

/*

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

*/









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