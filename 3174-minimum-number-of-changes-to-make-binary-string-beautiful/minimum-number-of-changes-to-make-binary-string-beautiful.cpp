// Approach 2 -> 

class Solution {
public:
    int minChanges(string s) {
        int n= s.length();
        
        int changes= 0;
        int cnt= 0;

        char prev= s[0];
        for(int i=0; i<n; i++)
        {
            if(s[i]== prev)
            {
                cnt++;
            }
            
            // if s[i] != s[i-1]
            else
            {
                // start a new group,
                if(cnt % 2!= 0)
                {
                    changes++;
                    cnt= 0;
                }
                else
                {
                    cnt= 1;
                }

                prev= s[i];
            }
        }
    return changes;
    }
};






// Approach 1 -> Best Approach
// TC= O(N)

/*

class Solution {
public:
    int minChanges(string s) {
        int n= s.length();
        
        int changes= 0;
        for(int i=0; i<n; i+=2)
        {
           if(s[i] != s[i+1])
           {
              changes++;
           }
        }
      return changes;  
    }
};

*/