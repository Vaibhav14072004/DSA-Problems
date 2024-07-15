// TC= O(N)

class Solution {
public:
    string getSmallestString(string s, int k) {
        int n= s.length();
        
        string ans= "";
        for(int i=0; i<n; i++)
        {
            // first try to convert to char 'a' from the distance k if possible..
            int left= s[i]-'a';
            int right= 'z'-s[i]+1;

            if(k >= min(left,right))
            {
                k= k- min(left,right);
                ans+= 'a';
            }

        // if k cannot convert curr char into 'a' then reduce this char by remaining k...
            else
            {
               ans+= s[i]-k;
               k= 0;
            }
        }
        return ans;
    }
};