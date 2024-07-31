// Approach 1 -> DP (Memoization)
// TC= O(N^2)

class Solution{
public:
   int solve(int index, vector<vector<int>> &books, int remWidth, int shelfWidth, int maxHt, vector<vector<int>> &dp)
   {
        // base case
        if(index >= books.size())
        {
            return maxHt;
        }

        if(dp[index][remWidth] != -1)
        {
            return dp[index][remWidth];
        }

        int width= books[index][0];
        int height= books[index][1];

        // keep the box in curr row...
        int keep= INT_MAX;
        if(width <= remWidth)
        {
            keep= solve(index+1, books, remWidth-width, shelfWidth, max(maxHt, height), dp);
        }
        
        // skip the book, put it in another row...
        int skip= maxHt+ solve(index+1, books, shelfWidth-width, shelfWidth, height, dp);

        return dp[index][remWidth]= min(keep, skip);
   }
   

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth)
    {
        int n= books.size();

        // 2D DP ->> 2 variables changing (Index and remWidth)
        vector<vector<int>> dp(n, vector<int>(shelfWidth + 1, -1));
        return solve(0, books,shelfWidth, shelfWidth, 0, dp);
    }
};








/*   ----- RECURSION CODE -----
    **** TC= O(2^N)  *****

class Solution {
public:
    int solve(int index, vector<vector<int>> &books, int remWidth, int maxHt, int shelfWidth)
    {
        // base case
        if(index >= books.size())
        {
           return maxHt;
        }

          int width= books[index][0];
          int height= books[index][1];

          // keep the book in curr row..
          int keep= INT_MAX;
          if(width <= remWidth)
          {
            keep= solve(index+1, books, remWidth-width, max(maxHt, height), shelfWidth);
          }

          // Keep the curr book in next row...
          int skip= maxHt+ solve(index+1, books, shelfWidth-width , height, shelfWidth);

          return min(skip, keep);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        return solve(0, books, shelfWidth,0, shelfWidth);
    }
};

*/