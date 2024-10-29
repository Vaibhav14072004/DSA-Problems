// TC= O(N)

class Solution {
public:
    int maxOperations(string s) {
        int n= s.length();
        
        int ones= 0, ans= 0;
        for(int i=0; i<n; i++)
        {
           if(s[i]== '1')
           {
              ones++;
           }
           
           if(i>=1 && s[i-1]== '1' && s[i]== '0')
           {
               ans+= ones;
           }
        }
        return ans;
    }
};