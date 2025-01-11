// Odd freq of chars is the only concern for us...
// (odd freq) <= k, return true bcoz we can either merge the odd freq element in middle or as separate singe palindrome

// TC= O(N)

class Solution {
public:
    bool canConstruct(string str, int k) {
        int n= str.size();
        
        // we can break all chars of str as single palindromes separately.
        if(n== k){
            return true;
        }
       
        if(k > n){
         return false;
        }

        // now cnt how many chars have odd freq...
        vector<int> freq(26,0);

        for(int i=0; i<n; i++)
        {
            freq[str[i]-'a']++;
        }
        
         int cntOdd= 0;
        for(int i=0; i<26; i++)
        {
            if(freq[i] % 2 == 1){
                cntOdd++;
            }
        }

        if(cntOdd <= k)
        {
            return true;
        }
       
       // if cntOdd > k
      return false;
    }
};