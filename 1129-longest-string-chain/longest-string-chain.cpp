// Approach 1 -> DP (Memoization)
// TC= O(N log N) + O[N^2 * (n1+n2)]

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