// Approach 3.2 -> 1D Dp (Tabulation) 

// we can either run (i from 0 to n-1) and (j from i-1 to 0)

// OR we can run (i from n-1 to 0) and (j from i+1 to n)

// TC= O(N log N) + O[(n1+n2)* N^2]
// SC= O(N)


class Solution{
public:
    bool isPred(string &prevStr, string &currStr)
    {
        int n1= prevStr.size();
        int n2= currStr.size();

         if(n2-n1 != 1){
            return false;
         }

         int i=0, j=0;
         while(i < n1 && j < n2)
         {
            // currStr has > length than prevStr..
             if(prevStr[i] != currStr[j])
             {
                j++;
             }
             else 
             {
                i++;
                j++;
             }
         }
      return i== n1;
    } 
  
  
    static bool cmp(string &a, string &b)
    {
        return a.length() < b.length();
    }

    int longestStrChain(vector<string>& words)
    {
        int n= words.size(); 
        sort(words.begin(), words.end(), cmp);  // sort in ascending order...
       
       // we can take only 1 individual as string chain also...
        vector<int> dp(n, 1);
        
        int ans= 1;
        for(int i= 0; i<n; i++)
        {
            for(int j= i-1; j>=0; j--)
            {
                if(isPred(words[j],words[i]))
                {
                    dp[i]= max(dp[i], 1+ dp[j]);
                }
            }
            ans= max(ans, dp[i]);
        }  
    return ans;
    }
};







// Approach 3 -> 1D Dp (Memoization) -> Using for loop

// TC= O(N log N) + O[(n1+n2)* N^2]

// SC= O(N)

/*

class Solution{
public: 
    bool isPred(string &prevStr, string &currStr)
    {
         int n1= prevStr.size();
         int n2= currStr.size();

         if(n2-n1 != 1){
            return false;
         }

         int i=0, j=0;
         while(i < n1 && j < n2)
         {
            // currStr has > length than prevStr..
             if(prevStr[i] != currStr[j])
             {
                j++;
             }
             else 
             {
                i++;
                j++;
             }
         }
      return i== n1;
    }


    int solve(int index, vector<string> &words, vector<int> &dp)
    {
        int n= words.size();

         // base case
         if(index== n)
         {
            return 0;
         }

         if(dp[index] != -1)
         {
            return dp[index];
         }
        
        // ans is starting from 1 bcoz we can consider single element as chain also.
        int ans= 1;
         for(int j= index+1; j<n; j++)
         {
            if(isPred(words[index], words[j]))
            {
                ans= max(ans, 1 + solve(j,words,dp));
            }
         }
    return dp[index]= ans;
    }

  
    static bool cmp(string &a, string &b)
    {
        return a.length() < b.length();
    }
  

    int longestStrChain(vector<string>& words)
    {
        int n= words.size(); 
        sort(words.begin(), words.end(), cmp);  // sort in ascending order...

        vector<int> dp(n, -1);
        
        int ans= 1;
        for(int i=0; i<n; i++)
        {
            ans= max(ans, solve(i, words, dp));
        }
    return ans;
    }
};

*/






// Approach 1 -> 2D DP ->> LIS Pattern

// TC= O(N log N) + O[N^2 * (n1+n2)]

// SC= O(N^2)

/*

class Solution{
public:
    bool isPred(string &prevStr, string &currStr)
    {
         int n1= prevStr.length();
         int n2= currStr.length();

         if(n2-n1 != 1)
         {
            return false;
         }

         int i=0,j=0;
         while(i < n1 && j < n2)
         {
            // currStr has > length than prev string
            if(prevStr[i] != currStr[j])
            {
                j++;
            }
            else
            {
                i++;
                j++;
            }
         }
      return i== n1; 
    }


    int solve(int curr, int prev, vector<string> &words, vector<vector<int>> &dp)
    { 
         // bae case
         if(curr== words.size()){
            return 0;
         }

         if(dp[curr][prev+1] != -1)
         {
             return dp[curr][prev+1];
         }

         // 1. include the curr words if it is predecessor...
         int include= INT_MIN;

         if(prev== -1 || isPred(words[prev], words[curr]))
         {
            include= 1 + solve(curr+1, curr, words, dp);
         }

         int exclude= solve(curr+1, prev, words, dp);

         return dp[curr][prev+1]= max(include,exclude);
    }


    static bool cmp(string &a, string &b)
    {
        return a.length() < b.length();
    }
  

    int longestStrChain(vector<string>& words)
    {
        int n= words.size();

        // sort in ascending order of length...
        sort(words.begin(), words.end(), cmp);

        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return solve(0, -1, words, dp);
    }
};

*/









/*  RECURSIVE CODE 
   **** TC= O(N log N) + O [(N1+N2)* 2^N]  ****

class Solution {
public:
    bool isPred(string &a, string &b)
    {
        int n1= a.length();
        int n2= b.length();

         if(n2-n1 != 1)
         {
            return false;
         }

         int i=0, j=0;
         while(i < n1 && j < n2)
         {
            // b is having greater length...
             if(a[i] != b[j])
             {
                j++;
             }

             else
             {
                i++;
                j++;
             }
         }

         return i== n1;
    }


    int solve(int curr, int prev, vector<string> &words)
    {   
         // base case
         if(curr == words.size())
         {
            return 0;
         }

         // 1. call for include....
         int include= INT_MIN;

         if(prev== -1 || isPred(words[prev],words[curr]))
         {
            include= 1+ solve(curr+1, curr, words);
         }

         int exclude= solve(curr+1, prev, words);
         return max(include, exclude);
    }


    static bool cmp(string &a, string &b)
    {
        return a.length() < b.length();
    }


    int longestStrChain(vector<string>& words)
    {
        // sort in ascending order of length...
        sort(words.begin(), words.end(), cmp);
        return solve(0,-1,words);
    }
};

*/


