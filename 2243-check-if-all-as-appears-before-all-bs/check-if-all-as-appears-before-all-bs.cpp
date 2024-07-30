// TC= O(N)

class Solution {
public:
    bool checkString(string s) {
        int n= s.length();

        bool found= false;
        for(int i=0; i<n; i++)
        {
            if(s[i] == 'b')
            {
               found= true;
            }
            else if(found== true && s[i]== 'a')
            {
                return false;
            }

            // if found== false && s[i]== 'a' ... then continue;
            else
            {
                continue;
            }
        }
      return true;  
    }
};