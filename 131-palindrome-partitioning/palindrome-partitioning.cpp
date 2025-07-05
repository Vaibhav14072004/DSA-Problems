// Approach 1 -> Backtracking
// TC= O(N* (2^N))

class Solution {
public:
    bool isPalindrome(string &str, int i, int j)
    {
        while(i <= j)
        {
            if(str[i] != str[j]){
                return false;
            }
          i++;
          j--;  
        }
      return true;  
    }


    void backtrack(int i, string &str, vector<string> &curr,vector<vector<string>> &ans){
        int n= str.length();

        // base case
        if(i== n)
        {
          ans.push_back(curr);
          return;
        }

        for(int j=i; j<n; j++)
        {
            if(isPalindrome(str,i,j))
            {
                // DO....
                curr.push_back(str.substr(i,j-i+1));
        
               // EXPLORE....
               backtrack(j+1,str,curr,ans);
            
               // BACKTRACK ....
               curr.pop_back();
            }
        }
    }


    vector<vector<string>> partition(string str) {
        int n= str.length();
        vector<vector<string>> ans;
        vector<string> curr;
        backtrack(0,str,curr,ans);
        return ans;
    }
};