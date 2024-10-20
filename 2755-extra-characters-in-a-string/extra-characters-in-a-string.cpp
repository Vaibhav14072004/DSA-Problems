// Approach 2 -> Bottom Up (Tabulation)
// TC= O(N^2)

class Solution{
public:
    int minExtraChar(string str, vector<string>& dict){
        int n= str.length();
        unordered_set<string> st(dict.begin(), dict.end());
        
        // In worst case extra full string is extra, so initialize with n
        vector<int> dp(n+1,n);

        // base case, no extra characters when considering an empty string from position n onwards
        dp[n]= 0;
        
        for(int i=n-1; i>=0; i--)
        {
            string curr= "";
            for(int j= i; j<n; j++)
            {
                curr+= str[j];
                int extra= 0;

                if(st.find(curr) == st.end())
                {
                    extra+= curr.length();
                }

                dp[i]= min(dp[i], extra+ dp[j+1]);
            }
        }
        return dp[0];
    }
};







// Approach 1 -> Top Down Approach (Recursion + Memoization)
// TC= O(N^2)

/*

class Solution{
public:
    int solve(int idx, string str, vector<string> &dict, unordered_set<string> &st, vector<int> &dp)
    {
        int n= str.length();

         // base case
         if(idx >= n){
            return 0;
         }

         if(dp[idx] != -1){
            return dp[idx];
         }
         
         int mini= INT_MAX;
         string curr= "";

         for(int i= idx; i<n; i++){
            curr+= str[i];
            int extraChar= 0;

            if(st.find(curr) == st.end())
            {
                extraChar= curr.length();
            }
            
            int rem= solve(i+1,str,dict,st,dp);
            mini= min(mini, rem+ extraChar);
         } 
       return dp[idx]= mini;   
    }


    int minExtraChar(string str, vector<string>& dict){
        int n= str.length();

        unordered_set<string> st(dict.begin(),dict.end());
        vector<int> dp(n+1,-1);
        return solve(0,str,dict,st,dp);
    }    
};

*/







/* WRONG APPROACH -> Set, Map Cannot be used 

class Solution{
public:
   int minExtraChar(string str, vector<string>& dictionary) {
        unordered_map<char,int> mp;

        for(int i=0; i<dictionary.size(); i++)
        {
             for(int j=0; j<dictionary[i].size(); j++)
             {
                mp[str[j]]++;
             }
        }
        
        int ans= 0;
        for(int i=0; i<str.length(); i++)
        {
           mp[str[i]]--;
        }

        for(auto it: mp)
        {
            if(it.second > 0)
            {
                ans+= it.second;
                it.second= 0
            }
        }
    return ans/2;
   }
};

*/





