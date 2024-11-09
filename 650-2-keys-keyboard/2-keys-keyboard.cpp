// Approach 1 -> Recursion + Memoization
// TC= O(N^2)

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

        return min(case1,case2);
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