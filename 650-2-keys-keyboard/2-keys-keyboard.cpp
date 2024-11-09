// Approach 2 -> Bottom Up + Greedy
// TC= O(N^2)

class Solution{
public:  
    int minSteps(int n)
    {    
       if(n == 0 || n== 1){
          return 0;
       }

       if(n== 2){
          return 2;
       }
       
       // dp[i] -> means minimum steps to make i characters in clipboard
       vector<int> dp(n+1,0);

       // dp[0]= 0; dp[1]= 0;
       dp[2]= 2;

       for(int i=3; i<=n; i++)
       {
           // ex- if we have to make n= 27, start making from 27/2, if not div by 0,then 26/2= 13
           int factor= i/2;
           while(factor >= 1)
           {
               if(i % factor == 0)
               {
                   int steps_to_make_factor= dp[factor];
                   int copy= 1;
                   int paste= i/factor - 1;
                   
                   // min steps to make i no of A's in clipboard
                   dp[i]= dp[factor] + copy + paste;

                   break;
               }  

               // search for a smaller factor
               else
               {
                  factor--;
               }
           }
       }

    // min steps to make up n A's in clipboard   
    return dp[n];
    }
};






// Approach 1 -> Recursion + Memoization
// TC= O(N^2)

/*

class Solution{
public:
   int solve(int currA, int clip, int n, vector<vector<int>> &dp)
   {
        // base case
        if(currA == n)
        {
            return 0;
        }
        
        // it shows invalid case..
        if(currA > n)
        {
            return 100000;
        }

        if(dp[currA][clip] != -1)
        {
            return dp[currA][clip];
        }

        // Case 1 -> CopyAll + Paste
        int case1= 2 + solve(currA+ currA, currA, n, dp);

        //Case 2 -> Paste only
        int case2= 1 + solve(currA+ clip, clip, n, dp);

        return dp[currA][clip]= min(case1,case2);
   }

    int minSteps(int n)
    {    
       if(n <= 1){
          return 0;
       }
        
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));

        // 1 operation needed for copying the A to clip present initially in notepad
        return 1 + solve(1,1,n,dp);
    }
};

*/








/*  Easiest Approach

class Solution {
public:
    int minSteps(int n) {
        int steps = 0;
        for (int i = 2; i <= n; ++i) {
            while (n % i == 0) {
                steps += i;
                n /= i;
            }
        }
        return steps;
    }
};

*/