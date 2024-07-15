class Solution {
public:
    string getSmallestString(string s) {
        int n= s.length();
        
     
        for(int i=1; i<n; i++)
        {
            int prev= s[i-1]-'0'; // to convert it in integer,,,  
            int curr= s[i]-'0';

            if((prev % 2 == curr % 2) && prev > curr)
            {
               swap(s[i], s[i-1]);
               break;   // bcoz atmost 1 swap can be done...
            }
        }
    return s;
    }
};