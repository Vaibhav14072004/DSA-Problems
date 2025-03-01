// Using Bottom up approach -> (Length of shortest common supersequence)
// TC= O(N* M) for filling dp table + O(N + M) for making str from dp table

// TC= O(N*M) + O(N+M)
// SC= O(N*M)

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n= str1.length();
        int m= str2.length();
        vector<vector<int>> dp(n+1,vector<int> (m+1));
        
        for(int len1=0; len1<= n; len1++)
        {
            for(int len2=0; len2<= m; len2++)
            {
                // to handle base case -> if one string is finished,add other remaining string length
                if(len1== 0 || len2== 0)
                {
                    dp[len1][len2]= len1+ len2;
                }

                else if(str1[len1-1]== str2[len2-1])
                {
                    dp[len1][len2]= 1 + dp[len1-1][len2-1];
                }
                else
                {
                    dp[len1][len2]= 1+ min(dp[len1-1][len2], dp[len1][len2-1]);
                }
            }
        }
        
        string ans= "";
        int i=n, j= m;

        while(i > 0 && j> 0)
        {
           if(str1[i-1]== str2[j-1])
           {
               ans+= str1[i-1];
               i--;
               j--;
           }
           else
           {
               if(dp[i-1][j] < dp[i][j-1])
               {
                   ans+= str1[i-1];
                   i--;
               }
               else
               {
                   ans+= str2[j-1];
                   j--; 
               }
           }
        }

        // if 1 string is finished but other is NOT
        while(i > 0)
        {
            ans+= str1[i-1];
            i--;
        }

        while(j> 0)
        {
            ans+= str2[j-1];
            j--;
        }

        // reverse the final string...
        reverse(ans.begin(),ans.end());

      return ans;  
    }
};