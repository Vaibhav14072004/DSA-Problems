// TC= O(N^2)

class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n= s.length();
        int cnt= 0;

      // infinite loop...
    while(true)
    {
        bool found= false;
        for(int i=0; i<n-1; i++)
        {
            if(s[i]== '0' && s[i+1]== '1')
            {
                swap(s[i],s[i+1]);
                i++;
                found= true;
            }
        }
      
      if(!found)
      {
          break;
      }
    
    // in one iteration we can change all '01' to '10'
      cnt++;
    }

      return cnt;  
    }
};