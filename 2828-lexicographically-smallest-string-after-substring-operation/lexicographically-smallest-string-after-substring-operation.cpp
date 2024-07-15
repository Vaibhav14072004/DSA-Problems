// Substring ->> continous portion....

class Solution {
public:
    string smallestString(string s) {
        int n= s.length();

        bool flag= false;
        for(int i=0; i<n; i++)
        {
            if(s[i] > 'a')
            {
                s[i]= s[i]-1;
                flag= true;
            }

            // else if s[i] would become z,, then break..
            else if(flag)
            {
                break;
            }
        }
        
        // to handle the case when all chars are aaa .. 
        // in this way we have return aaz... converting last char to 'z'
        if(flag== false && s[n-1]== 'a'){
            s[n-1]= 'z';
        }
       return s; 
    }
};