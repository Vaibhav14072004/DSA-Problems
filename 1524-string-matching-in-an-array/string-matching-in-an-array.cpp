// Approach 1 -> Brute Force Approach
// Tc= O(N*M*N) ->> O(N^3)

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n= words.size();
        unordered_set<string> st;

        for(int i=0; i<n; i++)
        {
           for(int j=0; j<n; j++)
           {
               if(i== j) continue;

               if(words[j].find(words[i]) != string:: npos)
               {
                  st.insert(words[i]);
               }
           }
        }
        
        vector<string> ans(st.begin(),st.end());
        return ans;   
    }
};