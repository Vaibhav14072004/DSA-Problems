// TC= O(N)

class Solution {
public:
    bool doesAliceWin(string s) {
        int n= s.length();
        int cnt= 0;
        
        unordered_set<char> st= {'a','e','i','o','u'};
        for(int i=0; i<n; i++)
        {
             if(st.find(s[i]) != st.end())
             {
                cnt++;
             }
        }
        
    // Alice will win always, bcoz it will take max odd vowels, bob will be left
    // with only 0 or 1 vowel...
        if(cnt >=1 )
        {
            return true;
        }
      
    return false;
    }
};