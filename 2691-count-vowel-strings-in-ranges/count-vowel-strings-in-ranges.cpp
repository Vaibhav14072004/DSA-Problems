// Approach 1 ->>  Using Prefix Array
// TC= O(N + Q)

class Solution {
public:
    bool isVowel(char ch)
    {
        if(ch== 'a' || ch== 'e' || ch== 'i' || ch== 'o' || ch== 'u')
        {
            return true;
        }
      return false;  
    }


    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n= words.size();
        int q= queries.size();
        
        vector<int> prefixVowels(n,0);
        if(isVowel(words[0][0]) && isVowel(words[0].back()))
        {
            prefixVowels[0]= 1;
        }

        for(int i=1; i<n; i++)
        {
            if(isVowel(words[i][0]) && isVowel(words[i].back()))
            {
                prefixVowels[i]= prefixVowels[i-1]+1;
            }
            else
            {
                prefixVowels[i]= prefixVowels[i-1];
            }
        }
        
        vector<int> ans(q,0);
        for(int i=0; i<q; i++)
        {
            int start= queries[i][0];
            int end= queries[i][1];

            if(start== 0)
            {
                ans[i]= prefixVowels[end];
            }
            else
            {
                ans[i]= prefixVowels[end]- prefixVowels[start-1];
            }
        } 
      return ans;  
    }
};