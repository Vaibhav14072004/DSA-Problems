// TC= O(N)

class Solution {
public:
    int minAddToMakeValid(string s) {
        int n= s.length();
        
        int open= 0;
        int unbalance= 0;
        for(int i=0; i<n; i++)
        {
            if(s[i]== '(')
            {
                open++;
            }
            
            // if open > 0, we have '(' then if we get closing bracket s[i]== ')', they get balance
            else if(open > 0)
            {
               open--;
            }

            else
            {
                unbalance++;
            }
        }

        return unbalance+open;
    }
};