class Solution {
public:
    bool isVowel(char ch)
    {
        return true ? (ch== 'a' || ch== 'e' || ch== 'i' || ch== 'o' || ch== 'u') : false;
    }

    int maxFreqSum(string s) {
        int n= s.length();
        int maxVowel= 0, maxC= 0;
        
        vector<int> freq(26,0);
        for(int i=0; i<n; i++)
        {
            freq[s[i]-'a']++;
        }

        for(int i=0; i<26; i++)
        {
            char ch= i+ 'a';
            if(isVowel(ch))
            {
                maxVowel= max(maxVowel,freq[i]);
            }
            else
            {
                maxC= max(maxC,freq[i]);
            }
        }
      return maxVowel+ maxC;  
    }
};