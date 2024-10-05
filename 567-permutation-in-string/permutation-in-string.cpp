// TC= O(M+N)
// SC= O(1)

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1= s1.length();
        int n2= s2.length();
        
        // base case
        if(n1 > n2) return false;

        vector<int> mp1(26,0);
        vector<int> mp2(26,0);
        
        for(int i=0; i<n1; i++)
        {
            mp1[s1[i]- 'a']++;
        }

        int i=0, j= 0;
        while(j < n2)
        {
            mp2[s2[j]- 'a']++;

            // shrink the curr window if its size becomes > s1
            if(j-i+1 > n1)
            {
               mp2[s2[i]- 'a']--;  
               i++; 
            }

            if(mp1== mp2)
            {
                return true;
            }
            j++;    
        }
     return false; 
    }
};