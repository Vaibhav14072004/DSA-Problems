class Solution {
public:
    bool canChange(string s, string t) {
        int n= s.size();
        int i=0,j=0;
        while(i<n || j<n){
          while(i<n && s[i]=='_') i++;
          while(j<n && t[j]=='_')j++;
            if(i==n && j==n) return true;

            if(s[i]!=t[j]) return false;

            if(s[i]=='L' && i<j) return false;
            if(s[i]=='R' && i>j) return false;
            i++;
            j++;

        }
        return true;



    }
};