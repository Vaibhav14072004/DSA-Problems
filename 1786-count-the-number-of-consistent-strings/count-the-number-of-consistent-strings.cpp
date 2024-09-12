// Approach 1 -> USing set
// TC= O(N^2)

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int n= words.size();
        
        unordered_set<char> st(allowed.begin(), allowed.end());
        
        int ans= 0;
        for(int i=0; i<n; i++)
        { 
            bool consistent= true;
            for(int j=0; j<words[i].size(); j++)
            {
                if(st.find(words[i][j]) == st.end())
                {
                    consistent= false;
                    break;
                }
            }
          
          if(consistent)
             ans++;
        }
      return ans;  
    }
};