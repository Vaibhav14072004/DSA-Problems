// Approach -> Brute Force Approach
// TC= O[N*N*N] ->> O(N^3)

class Solution {
public:
// func to check whether string a is suffix as well as prefix of string b
    bool isPrefixSuffix(string a, string b)
    {
         int lenA= a.length();
         int lenB= b.length();

         for(int i=0; i<lenA; i++)
         {
            if((a[i] != b[i]) || (a[lenA-i-1] != b[lenB-i-1]))
            {
                return false;
            }
         }
        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int n= words.size();
        int cnt= 0;

        for(int i=0; i<n; i++)
        {
            for(int j= i+1; j<n; j++)
            {
                if(isPrefixSuffix(words[i],words[j]))
                {
                    cnt++;
                }
            }
        }
      return cnt;  
    }
};