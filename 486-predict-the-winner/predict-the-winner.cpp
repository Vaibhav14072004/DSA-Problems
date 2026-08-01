/*
1. If u select i =>> opponent has to choose from array (i+1 -> j)
  a) If opponent chooses i+1 .... then u have to choose (i+2, j)
  b) If opponent chooses j.... then u have to choose from (i+1,j-1)

2. If u select j =>> opponent has to choose from array (i -> j-1)
  a) If opponent chooses i... then u have to choose (i+1, j-1)
  b) If opponent chooses j... then u have to choose from (i, j-2)

Opponent will minimise your score .... but u need to maximize it...

  int solve1= arr[i]+ min(solve(i+2,j,arr,dp), solve(i+1,j-1,arr,dp));
  int solve2= arr[j]+ min(solve(i+1,j-1,arr,dp), solve(i,j-2,arr,dp)); 

  return max(solve1, solve2);
  
  Now check if this score returned by function > (total+1)/2 return true
  else return false

*/

// TC= O(n^2)
// SC= O(n^2)

class Solution {
public:
    int solve(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
    {
        int n= arr.size();
         
         if(i> j){
            return 0;
         }

         if(i== j){
            return arr[i];
         }

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
       
            int solve1= arr[i]+ min(solve(i+2,j,arr,dp), solve(i+1,j-1,arr,dp));
            int solve2= arr[j]+ min(solve(i+1,j-1,arr,dp), solve(i,j-2,arr,dp));

            return dp[i][j]= max(solve1,solve2);
    }


    bool predictTheWinner(vector<int>& arr) {
        int n= arr.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
       
       int totalSum= 0;
        for(int i=0; i<n; i++)
        {
            totalSum+= arr[i];
        }

    // If the first player's score is greater than or equal to half of the total sum, then the first player can win; otherwise, the second player will win.
       return solve(0,n-1,arr,dp) >= (totalSum+1)/2;
    }
};