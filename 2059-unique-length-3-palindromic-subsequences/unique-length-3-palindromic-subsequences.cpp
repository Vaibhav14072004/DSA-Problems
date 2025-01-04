// TC= O(26*N + N) ->>O(N)
// SC= O(26) ->> O(1)

class Solution {
public:
    int countPalindromicSubsequence(string str) {
        int n= str.length();
        
        // store first and last occurence of each character..
        unordered_map<char,pair<int,int>> mp;
        for(int i=0; i<n; i++)
        {
            if(mp.count(str[i]))
            {
                mp[str[i]].second= i;
            }
            else
            {
                mp[str[i]]= {i,i};
            }  
        }
         
        int cnt= 0;
        for(auto it: mp)
        {
            int firstIdx= it.second.first;
            int secondIdx= it.second.second;
            if(firstIdx == secondIdx)
            {
                continue;
            }   
            
            unordered_set<char> st;

            // now find unique chars from firstIdx+1 to secondIdx-1
            for(int i= firstIdx+1; i<= secondIdx-1; i++)
            {
                st.insert(str[i]);
            }
            cnt+= st.size();   
        }
      return cnt;    
    }
};