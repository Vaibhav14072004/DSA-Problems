// Approach -> Brute Force 
// TC= O(N^2* 26)

class Solution {
public:
    bool isBalanced(vector<int> &freq)
    {
        int same= 0;
        for(int i=0; i<26; i++)
        {
            if(freq[i]== 0) continue;
            else if(same== 0) same= freq[i];
            else if(same != freq[i])
            {
                return false;
            }
        }
      return true;  
    }

    int longestBalanced(string str) {
        int n= str.length();
        int maxLen= 0;  

        for(int i=0; i<n; i++)
        {
            vector<int> freq(26,0);
            for(int j=i; j<n; j++)
            {
                freq[str[j]-'a']++;
                if(isBalanced(freq))
                {
                    maxLen= max(maxLen, j-i+1);
                }
            }
        }
    return maxLen;    
    }
};